#ifndef _CANDIDATO_HPP_
#define _CANDIDATO_HPP_

using namespace std;

#include <string>

#include "Partido.hpp"

class Candidato {
private:
    string nome;
    int numero;
    Partido partido;

    int votos;

    string nascimento;
    int genero;
    int eleito;

    const int ELEITO_QP = 2;
    const int ELEITO_MEDIA = 3;

public:
    Candidato();
    Candidato(const string& nome, const int& numero, const Partido& partido, const string& nascimento, const int& eleito, const int& genero);
    string getNome() const;
    int getNumero() const;
    Partido getPartido() const;
    int getNumeroPartido() const;
    int getVotos() const;
    string getNascimento() const;
    int getEleito() const;
    void somaVotos(int qtdVotos);
    int getIdade() const;
    bool getCandidadoFoiEleito() const;
    void printCandidato() const;
};

#endif // !_CANDIDATO_HPP_
