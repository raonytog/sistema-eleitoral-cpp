using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Relatorios.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 4) {
        cout << "Quantidade de argumentos insuficiente para funcionamento do programa\n" << endl;
        return 0;
    }

    int codUE = stoi(argv[1]);
    string candidatos = argv[2], votos = argv[3], data = argv[4];

    SistemaEleitoral *sistema = new SistemaEleitoral(codUE, candidatos, data);
    sistema->ContabilizaVotos(votos);
    
    Relatorios *relatorios = new Relatorios(sistema);
    relatorios->geraRelatorios();

    sistema->liberaSistemaEleitoral();
    delete relatorios;
    delete sistema;
    
    return 0;
}
