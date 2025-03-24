#include "SistemaEleitora.hpp"

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static string removeAspas(string s) {
    s.erase(s.begin());
    s.erase(s.end()-1);
    return s;
}

static bool comparaCandidatos(Candidato* a, Candidato* b) {
    if (a->getVotos() != b->getVotos()) 
        return a->getVotos() > b->getVotos();
    return a->getIdade() < b->getIdade();
}

static bool comparaPartidos(Partido *a, Partido *b) {
    int totalA = a->getVotosNominais() + a->getVotosLegenda(), 
        totalB = b->getVotosNominais() + b->getVotosLegenda();

    if (totalB - totalA != 0) return totalB - totalA;
    return a->getNumero() - b->getNumero();
}

static bool comparaPartidosPorCandidato(Partido *a, Partido *b) {
    Candidato *c = a->getMaisVotado(),
              *d = b->getMaisVotado();

    if (c == NULL && d == NULL) return 0;
    else if (c == NULL) return -1;
    else if (d == NULL) return 1;

    int e = c->getVotos(), f = d->getVotos();
    if (f - e != 0) return f - e;
    return -999;
    // return Period.between(d.getNascimento(), c.getNascimento()).getDays();
}

SistemaEleitoral::SistemaEleitoral(int &codMunicipio, string &pathCandidatos, string &diaVotacao) {
    ifstream in(pathCandidatos);
    string line, aux;
    getline(in, line);

    this->codMunicipio = codMunicipio;

    string nomeCandidato = "", siglaPartido = "", nascimento = "";
    int numeroCandidato = 0, codUE = 0, codCargo = 0, eleito = 0, numeroPartido = 0, numeroFederacao = 0;
    bool genero = 0;

    while (getline(in, line)) {
        istringstream lineStream(line);
        
        /** 
        * as colunas relevantes e suas informacões 
        * 11 - codigo do municipio
        * 13 - codigo do cargo
        * 16 - numero de votacao do candidato a vereador
        * 18 - nome do candidato a vereador
        * 25 - numero do partido pertencente
        * 26 - sigla do partido pertencente
        * 28 - numero da federacao pertencente ao partido do candidato
        * 36 - data de nascimento do candidato
        * 38 - genero do candidato a vereador
        * 48 - situacao de eleicao do candidato (se foi eleito por media, por legenda, ...)
        */
        for (int i = 0; i < 50; i++) {
            getline(lineStream, aux, ';');

            if (i == 11) { codUE = stoi( removeAspas(aux) ); }
            else if (i == 13) { codCargo = stoi(aux); }
            else if (i == 16) { numeroCandidato = stoi(aux); } 
            else if (i == 18) { nomeCandidato = removeAspas(aux); } 
            else if (i == 25) { numeroPartido = stoi(aux); } 
            else if (i == 26) { siglaPartido = removeAspas(aux); } 
            else if (i == 28) { numeroFederacao = stoi(aux); } 
            else if (i == 36) { nascimento = aux; } 
            else if (i == 38) { genero = stoi(aux); } 
            else if (i == 48) { eleito = stoi(aux); }
        }

        /** Se o partido nao existir, cria e insere-o na hash */
        if (this->partidos.find(numeroPartido) == this->partidos.end()) {
            Partido *partido = new Partido(numeroPartido, siglaPartido, numeroFederacao);
            this->partidos.insert({numeroPartido, partido});
        }

        /** Caso seja o municipio em analise e vereador e o candidato continua na eleicao */
        if (codUE == codMunicipio && codCargo == CARGO_VEREADOR && eleito > CANDIDATURA_INVALIDA) {
            Candidato *candidato = new Candidato(nomeCandidato, numeroCandidato, *this->partidos.at(numeroPartido), nascimento, eleito, genero);
            this->candidatos.insert({numeroCandidato, candidato});

            if (candidato->getCandidatoFoiEleito()) {
                this->qtdEleitos++;
                this->eleitos.push_back(candidato);
            }
        }
    }

}

void SistemaEleitoral::ContabilizaVotos(string pathVotacao) {
    ifstream in(pathVotacao);
    string line, aux;
    getline(in, line);

    int numero = 0, codUE = 0, codCargo = 0, qtdVotos = 0;
    while (getline(in, line)) {
        istringstream lineStream(line);

        for (int i = 0; i < 26; i++) {
            getline(lineStream, aux, ';');
            if (i == 11) { codUE = stoi( removeAspas(aux) ); }
            else if (i == 17) { codCargo = stoi(aux); }
            else if (i == 19) { numero = stoi(aux); }
            else if (i == 21) { qtdVotos = stoi(aux); }

            if (i == 13 && codUE != this->codMunicipio) break;
            if (i == 17 && codCargo != CARGO_VEREADOR) break;
        }

        if (codUE == this->codMunicipio && codCargo == CARGO_VEREADOR) {
            if (numero <=  99) {
                if (this->partidos.find(numero) != this->partidos.end()) {
                    Partido *partido = this->partidos.at(numero);
                    if (partido != NULL) { 
                        partido->somaVotosLegenda(qtdVotos);
                        this->votosLegenda += qtdVotos;
                    }
                }

            } else {
                if (this->candidatos.find(numero) != this->candidatos.end()) {
                    Candidato *candidato = this->candidatos.at(numero);
                    if (candidato != NULL) {
                        candidato->somaVotos(qtdVotos);
                        this->votosNominais += qtdVotos;
                    }
                }
            }
        }
    }

    /** Ordena a colecao dos candidatos eleitos */
    
    for(const auto& pair : this->candidatos) {
        Candidato *c = pair.second;
        Partido *p = c->getPartido();
        p->addCandidato(c);
    }

    this->eleitos.sort(comparaCandidatos);
}

list<Partido*> SistemaEleitoral::ordenaPartidos() {
    list<Partido*> lista;
    for (const auto& pair : this->partidos) {
        lista.push_back(pair.second);
    }
    
    lista.sort(comparaPartidos);
    return lista;
}

/**
 * @return Lista de partidos ordenados de forma decrescente pelo numero de votos dos candidatos
 * mais votados de cada partido. Em caso de empate, o mais novo ganha
 */
list<Partido*> SistemaEleitoral::ordenaPartidosPorCandidato() {
    list<Partido*> lista;
    for (const auto& pair : this->partidos) {
        lista.push_back(pair.second);
    }
    
    lista.sort(comparaPartidosPorCandidato);
    return lista;
}

    /**
 * @return Lista de candidatos ordenados de forma decrescente pelo numero 
 * de votos dos candidatos. Em caso de empate, o mais novo ganha
 */
list<Candidato*> SistemaEleitoral::ordenaCandidatos() {
    list<Candidato*> lista;
    for (const auto& pair : this->candidatos) {
        lista.push_back(pair.second);
    }
    
    lista.sort(comparaCandidatos);
    return lista;
}

/**
 * @return Retorna a quantidade de vereadores eleitos na eleicao
 */
int SistemaEleitoral::getQtdEleitos() {
    return this->qtdEleitos;
}

/**
 * @return Retorna a lista de candidatos eleitos
 */
list<Candidato*> SistemaEleitoral::getCandidatosEleitos() {
    return this->eleitos;
}

/**
 * @return Retorna o dia da apuração dos votos
 */
// LocalDate SistemaEleitoral::getDiaVotacao() {
//     return this.diaVotacao;
// }

/**
 * @return Retorna a quantidade de votos de legenda
 */
int SistemaEleitoral::getVotosLegenda() {
    return this->votosLegenda;
}

/**
 * @return Retorna a quantidade de votos nominais
 */
int SistemaEleitoral::getVotosNominais() { 
    return this->votosNominais;
}
