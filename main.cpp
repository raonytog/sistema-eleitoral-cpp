using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Relatorios.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 4) {
        cout << "Quantidade de argumentos insuficiente para funcionamento do programa\n" << endl;
        // return 0;
    }

    int codUE = 1392;
    string candidatos = "testes/AC1392/in/candidatos.csv", votos = "testes/AC1392/in/votacao.csv";

    SistemaEleitoral *sistema = new SistemaEleitoral(codUE, candidatos, votos);
    sistema->ContabilizaVotos(votos);
    
    Relatorios *relatorios = new Relatorios(sistema);

    /** 1 */
    relatorios->imprimeNumeroDeVagas();
    cout << endl;

    /** 2 */
    relatorios->imprimeVereadoresEleitos();
    cout << endl;
    
    /** 3 */
    relatorios->imprimeCandidatosMaisVotados();
    cout << endl;
    
    /** 4 */
    relatorios->imprimeSeriamEleitos();
    cout << endl;

    /** 5 */
    relatorios->imprimeEleitosBeneficiados();
    cout << endl;

    /** 6 */
    //relatorios->imprimePartidosMaisVotados();
    cout << endl;

    /** 7 */
    //relatorios->imprimeExtremosDosPartidos();
    cout << endl;

    /** 8 */
    //relatorios->imprimeEleitosPorIdade();
    cout << endl;

    /** 9 */
    //relatorios->imprimeEleitosPorGenero();
    cout << endl;

    /** 10 */
    //relatorios->imprimePorcentagensDeVoto();
    cout << endl;
    
    return 0;
}
