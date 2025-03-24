#ifndef _RELATORIOS_HPP_
#define _RELATORIOS_HPP_

#include "SistemaEleitora.hpp"

using namespace std;

class Relatorios {
private:
    SistemaEleitoral *sistema;
public:
    Relatorios(SistemaEleitoral &sistema);
    SistemaEleitoral *getSistemaEleitoral();
    void imprimeNumeroDeVagas();
    void imprimeVereadoresEleitos();
    void imprimeCandidatosMaisVotados();
    void imprimeEleitosBeneficiados();
    void imprimePartidosMaisVotados();
    void imprimeExtremosDosPartidos();
    void imprimeEleitosPorIdade();
    void imprimeEleitosPorGenero();
    void imprimePorcentagensDeVoto();
};

#endif