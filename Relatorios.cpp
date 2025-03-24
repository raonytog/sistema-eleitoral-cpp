#include "Relatorios.hpp"

Relatorios::Relatorios(SistemaEleitoral *sistema) {
    this->sistema = sistema;
}

SistemaEleitoral *Relatorios::getSistemaEleitoral() {
    return this->sistema;
}

void Relatorios::imprimeNumeroDeVagas() {
    cout << "Número de vagas: " << this->getSistemaEleitoral()->getQtdEleitos() << endl;
}

void Relatorios::imprimeVereadoresEleitos() {
    cout << "Vereadores eleitos:" << endl;

    int i = 1;
    for (Candidato *candidato : this->getSistemaEleitoral()->getCandidatosEleitos()) {
        if (i > this->getSistemaEleitoral()->getQtdEleitos()) break;
        cout << i << " - ";
        cout << candidato->toString() << endl;
        i++;
     }
}
void Relatorios::imprimeCandidatosMaisVotados() {
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    list<Candidato*> maisVotados = this->getSistemaEleitoral()->ordenaCandidatos();
    int i = 1;
    for (Candidato* candidato : maisVotados) {
        if (i > this->getSistemaEleitoral()->getQtdEleitos()) break;
        cout << i << " - ";
        cout << candidato->toString() << endl;
        i++;
    }
}

void Relatorios::imprimeSeriamEleitos() {
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    list<Candidato*> maisVotados = this->getSistemaEleitoral()->ordenaCandidatos();

    int i = 1;
    for (Candidato *candidato : maisVotados) {
        if (i > this->getSistemaEleitoral()->getQtdEleitos()) break;

        if (candidato->getCandidatoFoiEleito() == false) {
            cout << i << " - ";
            cout << candidato->toString() << endl;
        }
        i++;
    }
}
void Relatorios::imprimeEleitosBeneficiados() {
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    list<Candidato*> maisVotados = this->getSistemaEleitoral()->ordenaCandidatos();
    int i = 1;
    for (Candidato *candidato : maisVotados) {
        if (i > this->getSistemaEleitoral()->getQtdEleitos() && candidato->getCandidatoFoiEleito()) {
            cout << i << " - ";
            cout << candidato->toString() << endl;
        }
        i++;
    }
}
void Relatorios::imprimePartidosMaisVotados() {}
void Relatorios::imprimeExtremosDosPartidos() {}
void Relatorios::imprimeEleitosPorIdade() {}
void Relatorios::imprimeEleitosPorGenero() {}
void Relatorios::imprimePorcentagensDeVoto() {}