#ifndef _PARTIDO_HPP_
#define _PARTIDO_HPP_

#include <string>
#include <list>

class Candidato;
#include "Candidato.hpp"

using namespace std;

class Partido {
private:
    string sigla;
    int numero;
    int federacao;

    int totalEleitos;
    int votosNominais;
    int votosLegenda;

    Candidato *maisVotado;
    Candidato *menosVotado;

public:
    Partido(const int& numero, const string& sigla, const int& federacao);
    int getNumero() const;
    string getSigla() const;
    int getFederacao() const;
    int getTotalEleitos() const;
    int getVotosNominais() const;
    int getVotosLegenda() const;
    int getVotosTotais() const;
    Candidato *getMaisVotado() const;
    Candidato *getMenosVotado() const;
    void setMaisVotado(Candidato *candidato);
    void setMenosVotado(Candidato *candidato);
    void addCandidato(Candidato *candidato);
    void somaVotosLegenda(int qtdVotos);
    void somaVotosNominais(int qtdVotos);
    void incrementaEleitos();
};

#endif // !_PARTIDO_HPP_