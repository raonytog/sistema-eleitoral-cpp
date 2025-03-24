#include "Candidato.hpp"
#include <iostream>

Candidato::Candidato(const string& nome, const int& numero, Partido& partido, const string& nascimento, const int& eleito, const bool& genero) {
    this->nome = nome;
    this->numero = numero;
    this->partido = &partido;
    this->nascimento = nascimento;
    this->eleito = eleito;
    this->genero = genero;

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
    return this->nascimento;
}

int Candidato::getEleito() const {
    return this->eleito;
}

void Candidato::somaVotos(int qtdVotos) { 
    this->votos += qtdVotos;
    this->partido->somaVotosNominais(qtdVotos);
}
int Candidato::getIdade() const {
    return 99999;
}

bool Candidato::getCandidatoFoiEleito() const {
    return this->getEleito() == this->ELEITO_MEDIA || this->getEleito() == this->ELEITO_QP;
}

void Candidato::printCandidato() const {
    cout << "teste" << endl;
}