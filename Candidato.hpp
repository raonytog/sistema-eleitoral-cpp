#ifndef _CANDIDATO_HPP_
#define _CANDIDATO_HPP_


#include <string>

class Partido;
#include "Partido.hpp"

using namespace std;

#define MULHER true
#define HOMEM false

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
    /**
     * @param nome Nome do candidato (nao necessita de ser o nome completo)
     * @param numero Numero de votacao do candidato
     * @param partido Partido ao qual o candidato pertence
     * @param nascimento Data de nascimento do candidat
     * @param eleito Situação de eleicão do candidato, se foi por média, legenda
     * @param genero Genero do candidato
     */
    Candidato(const string& nome, const int& numero, Partido &partido, const string& nascimento, const int& eleito, const bool& genero);
    
    /**
     * Pre condição: Candidato existente
     * @return Nome do candidato
     */
    string getNome() const;

    /**
     * Pre condição: Candidato existente
     * @return Numero para votar do candidato
     */
    int getNumero() const;

    /**
     * Pre condição: Candidato existente
     * @return Partido ao qual o candidato pertence
     */
    Partido *getPartido() const;

    /**
     * Pre condição: Candidato existente
     * @return Numero de votação para o partido do candidato
     */
    int getNumeroPartido() const;

    /**
    * Pre condição: Candidato existente
    * @return Quantidade de votos obtidas pelo candidato
    */
    int getVotos() const;

    /**
     * Pre condição: Candidato existente
     * @return Data de nascimento do candidato
     */
    string getNascimento() const;

    /**
     * Pre condição: Candidato existente
     * @return Situação de eleição do candidato: foi eleito, eleito por média, eleito por legenda
     */
    int getEleito() const;

     /**
     * Pre condição: Candidato existente
     * @return Genero de identificação do candidato
     * True, se for mulher, False, se for homem
     */
    bool getGenero() const;

    /**
     * Pre condição: Candidato existente
     * Aumenta o número de votos do candidato, além de somar os votos ao partido ao qual o mesmo pertence
     */
    void somaVotos(int qtdVotos);

    /**
     * Pre condição: Candidato existente
     * @return Idade do candidato (em anos)
     */
    int getIdade(const string& dataVotacao) const;

    /**
    * Pre condição: Candidato existente
    * @return Retorna se o candidato foi eleito por media ou por legenda
    */
    bool getCandidatoFoiEleito() const;

    /**
     * Pre condicao: Candidato existente
     * @return string para impressao de um candidato
     */
    string toString() const;
};

#endif // !_CANDIDATO_HPP_
