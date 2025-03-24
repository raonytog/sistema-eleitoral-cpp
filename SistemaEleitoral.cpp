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

SistemaEleitoral::SistemaEleitoral(int &codMunicipio, string &pathCandidatos, string &diaVotacao) {
    ifstream in(pathCandidatos);
    string line, aux;
    getline(in, line);

    string nomeCandidato = "", siglaPartido = "", nascimento = "";
    int numeroCandidato = 0, codUE = 0, codCargo = 0, genero = 0, eleito = 0, numeroPartido = 0, numeroFederacao = 0;

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
            aux = removeAspas(aux);
            switch (i) {
                case 11: codUE = stoi(aux);
                case 13: codCargo = stoi(aux);
                case 16: numeroCandidato = stoi(aux);
                case 18: nomeCandidato = aux;
                case 25: numeroPartido = stoi(aux);
                case 26: siglaPartido = aux;
                case 28: numeroFederacao = stoi(aux);
                case 36: nascimento = aux;
                case 38: genero = stoi(aux);
                case 48: eleito = stoi(aux);
            }
        }

        /** Se o partido nao existir, cria e insere-o na hash */
        if (this->partidos.at(numeroPartido) == NULL) {
            Partido *partido = new Partido(numeroPartido, siglaPartido, numeroFederacao);
            this->partidos.insert({numeroPartido, partido});
        }

        /** Caso seja o municipio em analise e vereador e o candidato continua na eleicao */
        if (codUE == codMunicipio && codCargo == CARGO_VEREADOR && eleito > CANDIDATURA_INVALIDA) {
            Candidato *candidato = new Candidato(nomeCandidato, numeroCandidato, this->partidos.at(numeroPartido), nascimento, eleito, genero)
            this->candidatos.insert({numeroCandidato, candidato});

            if (candidato.getCandidatoFoiEleito()) {
                this->qtdEleitos++;
                this->eleitos.push_back(candidato);
            }
        }
    }
}

