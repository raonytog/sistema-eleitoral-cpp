#ifndef _RELATORIOS_HPP_
#define _RELATORIOS_HPP_

#include <locale>

#include "SistemaEleitora.hpp"

using namespace std;

class Relatorios {
private:
    SistemaEleitoral *sistema;
public:

    /**
     * @param sistema Inicializa o relatorio com o sistema eleitoral para manipulação dos dados
     * @return Relatorio criado
     */
    Relatorios(SistemaEleitoral *sistema);

     /**
     * @return Obtem o sistema eleitoral
     */
    SistemaEleitoral *getSistemaEleitoral();
    
    /**
     * Imprime o numero de vagas disponíveis para eleição, no caso dos vereadores
     */
    void imprimeNumeroDeVagas();

    /**
     * Imprime os vereadores eleitos no formato:
     * Caso faça parte de um partido de de federação, o mesmo será impresso com o "*" anterior ao nome
     * <indice> - <nome> (<sigla>, <quantidade de votos> votos)
     */
    void imprimeVereadoresEleitos();

     /**
    * Imprime os candidatos mais votados em ordem decrescente pelo número de vagas.
    * Em caso de empate, o candidato mais novo entra
    */
    void imprimeCandidatosMaisVotados();

     /**
     * Imprime os candidatos que seriam eleitos caso a votação fosse majoritária,
     * juntamente de sua posição no rankin dos mais votados
     */
    void imprimeSeriamEleitos();

    /**
     * Imprime os vereadores que foram eleitos por beneficio do sistema proporcional
     */
    void imprimeEleitosBeneficiados();

    /**
     * Imprime os partidos mais votados seguindo o formato:
     * <indice> - <silga> - <numero>, <votos totais> (<votos nominais> e <votos de legenda>), <total de eleitos> candidatos eleitos 
     */
    void imprimePartidosMaisVotados();

    /**
     * Imprime os candidatos mais votados de cada partido no seguinte formato:
     * <indice> - <sigla> - <nome do partido>, <nome do candidato> (<numero>, <votos>) / <nome do candidato> (<numero>, <votos>))
     */
    void imprimeExtremosDosPartidos();

    /**
     * Imprime a distribuição de idades dos candidatos e suas participações em porcentagem
     */
    void imprimeEleitosPorIdade();

    /**
     * Imprime a porcentagem de participação masculina e feminina na eleição
     */
    void imprimeEleitosPorGenero();

    /**
     * Imprime a quantidade e porcentagem de cada tipo de voto 
     */
    void imprimePorcentagensDeVoto();
};

#endif