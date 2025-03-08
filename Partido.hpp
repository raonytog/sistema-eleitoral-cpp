#ifndef _PARTIDO_HPP_
#define _PARTIDO_HPP_

using namespace std;

#include <string>
#include <list>

#include "Candidato.hpp"

class Partido {
private:
    string sigla;
    int numero;
    int federacao;

    int totalEleitos;
    int votosNominais;
    int votosLegenda;

    list<Candidato> candidatos;

    Candidato maisVotado;
    Candidato menosVotado;

public:
    Partido();
    Partido(const int& numero, const string& sigla, const int& federacao);
    int getNumero() const;
    string getSigla() const;
    int getFederacao() const;
    list<Candidato> getCandidatos() const;
    int getTotalEleitos() const;
    int getVotosNominais() const;
    int getVotosLegenda() const;
    int getVotosTotais() const;
    Candidato getMaisVotado() const;
    Candidato getMenosVotado() const;
    void setMaisVotado(Candidato candidato);
    void setMenosVotado(Candidato candidato);
    void addCandidato(Candidato candidato);
    void somaVotosLegenda(int qtdVotos);
    void somaVotosNominais(int qtdVotos);
    void incrementaEleitos();
};

#endif // !_PARTIDO_HPP_