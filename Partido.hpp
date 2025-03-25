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

    /**
     * Cria um partido a partir de seu numero para votação, sua sigla e um numero de federaçao
     * @param numero número de votação
     * @param sigla sigla do partido
     * @param federacao número da federação participante
     */
    Partido(const int& numero, const string& sigla, const int& federacao);

    /**
     * Pre condição: Partido existente
     * @return Retorna o numero de votacao para o partido
     */
    int getNumero() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna a sigla do partido
     */
    string getSigla() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna um numero de federação > 0 caso o partido pertença a alguma federação
     */
    int getFederacao() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna numero total vereadores eleitos no partido
     */
    int getTotalEleitos() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna numero total votos nominais recorrentes no partido
     */
    int getVotosNominais() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna numero total votos de legenda recorrentes no partido
     */
    int getVotosLegenda() const;

     /**
     * Pre condição: Partido existente
     * @return Retorna a soma dos votos nominais e de legenda do partido
     */
    int getVotosTotais() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna o candidato mais votado do partido
     */
    Candidato *getMaisVotado() const;

    /**
     * Pre condição: Partido existente
     * @return Retorna o candidato menos votado do partido
     */
    Candidato *getMenosVotado() const;

    /**
     * Pre condição: Partido existente
     * 
     * Seta o candidato como o mais votado do partido
     * @param candidato Candidato mais votado
     */
    void setMaisVotado(Candidato *candidato);

    /**
     * Pre condição: Partido existente
     * 
     * Seta o candidato como o menos votado do partido
     * @param candidato Candidato menos votado
     */
    void setMenosVotado(Candidato *candidato);

    /**
     * Pre condição: Partido existente
     * 
     * Adiciona um candidato como mais ou menos votado, seguindo os criterios de:
     * numero de votos e mais velho.
     * 
     * Caso o candidato nao entre no mais ou menos votado, sai da funcao
     * @param candidato candidato a ser adicionado
     */
    void addCandidato(Candidato *candidato);

    /**
     * Pre condição: Partido existente
     * 
     * Aumenta a quantidade de votos de legenda do partido em 'qtdVotos'
     * @param qtdVotos quantidade de votos
     */
    void somaVotosLegenda(int qtdVotos);

    /**
     * Pre condição: Partido existente
     * Aumenta a quantidade de votos de nominais do partido em 'qtdVotos'
     * @param qtdVotos quantidade de votos
     */
    void somaVotosNominais(int qtdVotos);

     /**
     * Pre condição: Partido existente
     * 
     * Incrementa o total de eleitos no partido
     * @param qtdVotos quantidade de votos
     */
    void incrementaEleitos();

        /**
     * Pre condicao: Partido existente
     * @return string para impressao de um partido
     */
    string toString() const;
};

#endif // !_PARTIDO_HPP_