#ifndef _SISTEMA_ELEITORAL_HPP_
#define _SISTEMA_ELEITORAL_HPP_

#include <bits/stdc++.h>

#include "Candidato.hpp"
#include "Partido.hpp"

#define CARGO_VEREADOR 13
#define CANDIDATURA_INVALIDA -1

using namespace std;

class SistemaEleitoral {
private:
    map<int, Candidato*> candidatos;
    map<int, Partido*> partidos;
    
    list<Candidato*> eleitos;
    string diaDepuracao;

    int qtdEleitos, votosLegenda, votosNominais;
    int codMunicipio;

public:
    SistemaEleitoral(int &codMunicipio, string &pathCandidatos, string &diaVotacao);
    void ContabilizaVotos(string pathVotacao);
    list<Partido*> ordenaPartidos();
    list<Partido*> ordenaPartidosPorCandidato();
    list<Candidato*> ordenaCandidatos();
    int getQtdEleitos();
    list<Candidato*> getCandidatosEleitos();
    // getDiaVotacao();
    int getVotosLegenda();
    int getVotosNominais();
};

#endif