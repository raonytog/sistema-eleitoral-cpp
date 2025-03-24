#ifndef _CANDIDATO_HPP_
#define _CANDIDATO_HPP_


#include <string>

class Partido;
#include "Partido.hpp"

using namespace std;

class Candidato {
private:
    string nome;
    int numero;
    Partido *partido;

    int votos;

    string nascimento;
    bool genero;
    int eleito;

    const int ELEITO_QP = 2;
    const int ELEITO_MEDIA = 3;

public:
    Candidato(const string& nome, const int& numero, Partido& partido, const string& nascimento, const int& eleito, const bool& genero);
    string getNome() const;
    int getNumero() const;
    Partido *getPartido() const;
    int getNumeroPartido() const;
    int getVotos() const;
    string getNascimento() const;
    int getEleito() const;
    void somaVotos(int qtdVotos);
    int getIdade() const;
    bool getCandidatoFoiEleito() const;
    string toString() const;
};

#endif // !_CANDIDATO_HPP_
