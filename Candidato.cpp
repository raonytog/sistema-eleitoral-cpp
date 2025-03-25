#include "Candidato.hpp"

#include <ctime>
#include <sstream>
#include <iostream>
#include <sstream>

Candidato::Candidato(const string& nome, const int& numero, Partido& partido, const string& nascimento, const int& eleito, const bool& genero) {
    this->nome = nome;
    this->numero = numero;
    this->partido = &partido;
    this->nascimento = nascimento;
    this->eleito = eleito;
    this->genero = genero;
    this->votos = 0;

    if (this->getCandidatoFoiEleito()) this->getPartido()->incrementaEleitos();
}

string Candidato::getNome() const {
    return this->nome;
}

int Candidato::getNumero() const {
    return this->numero;
}

Partido* Candidato::getPartido() const {
    return this->partido;
}

int Candidato::getNumeroPartido() const {
    return this->getPartido()->getNumero();
}

int Candidato::getVotos() const {
    return this->votos;
}

string Candidato::getNascimento() const {
    string s = this->nascimento;
    s.erase(s.begin());
    s.erase(s.end()-1);
    return s;
}

int Candidato::getEleito() const {
    return this->eleito;
}

bool Candidato::getGenero() const {
    return this->genero;
}

void Candidato::somaVotos(int qtdVotos) { 
    this->votos += qtdVotos;
    this->partido->somaVotosNominais(qtdVotos);
}

int Candidato::getIdade(const string& dataVotacao) const {
    int diaNascimento, mesNascimento, anoNascimento;
    char delimiter;
    
    stringstream nascimentoStream( this->getNascimento()) ;
    nascimentoStream >> diaNascimento >> delimiter >> mesNascimento >> delimiter >> anoNascimento;

    int diaVotacao, mesVotacao, anoVotacao;
    stringstream votacaoStream(dataVotacao);
    votacaoStream >> diaVotacao >> delimiter >> mesVotacao >> delimiter >> anoVotacao;
    
    int age = anoVotacao - anoNascimento;
    if (mesVotacao < mesNascimento || (mesVotacao == mesNascimento && diaVotacao < diaNascimento)) {
        age--;
    }

    return age;
}

bool Candidato::getCandidatoFoiEleito() const {
    return this->getEleito() == this->ELEITO_MEDIA || this->getEleito() == this->ELEITO_QP;
}

string Candidato::toString() const {
    string answer;
    locale brLocale("pt_BR.UTF-8");
    stringstream votosFormatted, nomeFormatted;

    votosFormatted.imbue(brLocale);
    votosFormatted << this->getVotos();

    nomeFormatted.imbue(brLocale);
    nomeFormatted << this->getNome();
     
    if (this->partido->getFederacao() > 0) answer = "*" + nomeFormatted.str() + " (" + this->partido->getSigla() + ", " + votosFormatted.str() + " votos)";
    else  answer = nomeFormatted.str() + " (" + this->partido->getSigla() + ", " + votosFormatted.str() + " votos)";
    return answer;
}