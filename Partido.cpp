#include "Partido.hpp"
#include <iostream>

Partido::Partido() {
    this->sigla = "";
    this->numero = -1;
    this->federacao = -1;
    
    this->totalEleitos = -1;
    this->votosLegenda = -1;
    this->votosNominais = -1;
}

Partido::Partido(const int& numero, const string& sigla, const int& federacao) {
    this->numero = numero;
    this->sigla = sigla;
    this->federacao = federacao;
}

int Partido::getNumero() const {
    return this->numero;
}

string Partido::getSigla() const {
    return this->sigla;
}

int Partido::getFederacao() const {
    return this->federacao;
}

list<Candidato> Partido::getCandidatos() const {
    list<Candidato> copy(this->candidatos);
    return copy;
}

int Partido::getTotalEleitos() const {
    return this->totalEleitos;
}

int Partido::getVotosNominais() const {
    return this->votosNominais;
}

int Partido::getVotosLegenda() const {
    return this->votosLegenda;
}

int Partido::getVotosTotais() const {
    return this->getVotosLegenda() + this->getVotosNominais();
}

Candidato Partido::getMaisVotado() const {
    return this->maisVotado;
}

Candidato Partido::getMenosVotado() const {
    return this->menosVotado;
}

void Partido::setMaisVotado(Candidato candidato) {
    this->maisVotado = candidato;
}

void Partido::setMenosVotado(Candidato candidato) {
    this->menosVotado = candidato;
}

void Partido::addCandidato(Candidato candidato) {
    if (this->maisVotado == null && this->menosVotado == null) {
        setMaisVotado(candidato);
        setMenosVotado(candidato);
    }

    if (candidato.getVotos() > this->getMaisVotado().getVotos()) this->setMaisVotado(candidato);
    else if (candidato.getVotos() == this->getMaisVotado().getVotos()) {
        // if (Period.between(candidato.getNascimento(), this.getMaisVotado().getNascimento()).getDays() > 0) this.setMaisVotado(candidato);
    }

    if (candidato.getVotos() < this->getMenosVotado().getVotos()) this->setMenosVotado(candidato);
    else if (candidato.getVotos() == this->getMenosVotado().getVotos()) {
        // if (Period.between(candidato.getNascimento(), this.getMenosVotado().getNascimento()).getDays() < 0) this.setMenosVotado(candidato);
    }
}

void Partido::somaVotosLegenda(int qtdVotos) {
    this->votosLegenda += qtdVotos;
}

void Partido::somaVotosNominais(int qtdVotos) {
    this->votosNominais += qtdVotos;
}

void Partido::incrementaEleitos() {
    this->totalEleitos++;
}