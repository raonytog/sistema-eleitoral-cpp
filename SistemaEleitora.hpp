#ifndef _SISTEMA_ELEITORAL_HPP_
#define _SISTEMA_ELEITORAL_HPP_

#include <bits/stdc++.h>

#include "Candidato.hpp"
#include "Partido.hpp"

#define DATA_VOTACAO "06/10/2024"

#define CARGO_VEREADOR 13
#define CANDIDATURA_INVALIDA -1

using namespace std;

class SistemaEleitoral {
private:
    map<int, Candidato*> candidatos;
    map<int, Partido*> partidos;
    
    list<Candidato*> eleitos;
    string diaVotacao;

    int qtdEleitos, votosLegenda, votosNominais;
    int codMunicipio;

public:
    /**
     * Inicializa o sistema eleitoral, preenchendo seu conteudo com seus candidatos, partidos e
     * outras informações pertinentes, com o numero de votos para cada tipo de voto, além de
     * uma lista apenas com os candidatos a vereador eleitos
     * 
     * A leitura e validação dos atributos lidos necessitam que os valores inteiros 
     * estejam escritos sem aspas, com excessão no codigo do municipio, 
     * que será passado com aspas.
     * 
     * @param codMunicipio Codigo do municipio em análise
     * @param pathCandidatos Caminho para o arquivo csv com os candidatos
     * @param diaVotacao Dia que aconteceu a apuração dos dados de votacao
     */
    SistemaEleitoral(int &codMunicipio, string &pathCandidatos, string &diaVotacao);

    /**
     * Efetua a leitura e contabilizacao de votos para todos os candidatos e partidos existentes 
     * no sistema
     * 
     * A leitura e validação dos atributos lidos necessitam que os valores inteiros 
     * estejam escritos sem aspas, com excessão no codigo do municipio, 
     * que será passado com aspas.
     * 
     * @param pathVotacao Caminho para o arquivo csv com as informações de votação
     */
    void ContabilizaVotos(string pathVotacao);

    /**
     * @return Lista de partidos ordenados de forma decrescente por votos totais. 
     * Em caso de empate, a ordem fica com o que tiver maior número de votacao do partido
     */
    list<Partido*> ordenaPartidos();

    /**
     * @return Lista de partidos ordenados de forma decrescente pelo numero de votos dos candidatos
     * mais votados de cada partido. Em caso de empate, o mais novo ganha
     */
    list<Partido*> ordenaPartidosPorCandidato();

    /**
     * @return Lista de candidatos ordenados de forma decrescente pelo numero 
     * de votos dos candidatos. Em caso de empate, o mais novo ganha
     */
    list<Candidato*> ordenaCandidatos();

    /**
     * @return Retorna a quantidade de vereadores eleitos na eleicao
     */
    int getQtdEleitos();

    /**
     * @return Retorna a lista de candidatos eleitos
     */
    list<Candidato*> getCandidatosEleitos();

    /**
     * @return Retorna o dia da apuração dos votos
     */
    string getDiaVotacao() const;

    /**
     * @return Retorna a quantidade de votos de legenda
     */
    int getVotosLegenda();

    /**
     * @return Retorna a quantidade de votos nominais
     */
    int getVotosNominais();
};

#endif