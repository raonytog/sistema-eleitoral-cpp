#include "Relatorios.hpp"
#include <locale>

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
    cout << "Vereadoes eleitos:" << endl;

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
void Relatorios::imprimePartidosMaisVotados() {
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    list<Partido*> maisVotados = this->getSistemaEleitoral()->ordenaPartidos();
    int i = 1;
    for (Partido* partido : maisVotados) {
        ostringstream out;
        int v = partido->getVotosTotais();
        if (v > 1) out << i << " - " << partido->toString() << ", " << v << " votos ";
        else out << i << " - " << partido->toString() << ", " << v << " voto ";

        v = partido->getVotosNominais();
        if (v > 1) out << "(" << v << " nominais e ";
        else out << "(" << v << " nominal e ";

        out << partido->getVotosLegenda() << " de legenda), ";
        out << partido->getTotalEleitos();

        if (partido->getTotalEleitos() > 1) out << " candidatos eleitos";
        else out << " candidato eleito";

        cout << out.str() << endl;
        i++;
    }
}

void Relatorios::imprimeExtremosDosPartidos() {
    cout << "Primeiro e último colocados de cada partido:" << endl;

    list<Partido*> maisVotados = this->getSistemaEleitoral()->ordenaPartidosPorCandidato();
    int i = 1;
    for (Partido* partido : maisVotados) {
        if (partido->getMaisVotado() == nullptr || partido->getMenosVotado() == nullptr || partido->getVotosNominais() == 0) continue;

        ostringstream out;
        out << i << " - " << partido->toString() << ", ";
        
        out << partido->getMaisVotado()->getNome() << " (" << partido->getMaisVotado()->getNumero() << ", ";
        int v = partido->getMaisVotado()->getVotos();
        if (v > 1) out << v << " votos) / ";
        else out << v << " voto) / ";

        out << partido->getMenosVotado()->getNome() << " (" << partido->getMenosVotado()->getNumero() << ", ";
        v = partido->getMenosVotado()->getVotos();
        if (v > 1) out << v << " votos)";
        else out << v << " voto)";

        cout << out.str() << endl;
        i++;
    }
}

void Relatorios::imprimeEleitosPorIdade() {
    int total = this->getSistemaEleitoral()->getCandidatosEleitos().size();

    int idade, menorQue30 = 0, menorQue40 = 0, menorQue50 = 0, menorQue60 = 0, demais = 0;
    for (Candidato* c : this->getSistemaEleitoral()->getCandidatosEleitos()) {
        idade = c->getIdade(this->getSistemaEleitoral()->getDiaVotacao());
        if (idade < 30) menorQue30++;
        else if (idade < 40) menorQue40++;
        else if (idade < 50) menorQue50++;
        else if (idade < 60) menorQue60++;
        else demais++;
    }

    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    cout << "       Idade < 30: " << menorQue30 << " (" << fixed << setprecision(2) << (100.0 * menorQue30 / total) << "%)" << endl;
    cout << " 30 <= Idade < 40: " << menorQue40 << " (" << fixed << setprecision(2) << (100.0 * menorQue40 / total) << "%)" << endl;
    cout << " 40 <= Idade < 50: " << menorQue50 << " (" << fixed << setprecision(2) << (100.0 * menorQue50 / total) << "%)" << endl;
    cout << " 50 <= Idade < 60: " << menorQue60 << " (" << fixed << setprecision(2) << (100.0 * menorQue60 / total) << "%)" << endl;
    cout << " 60 <= Idade     : " << demais << " (" << fixed << setprecision(2) << (100.0 * demais / total) << "%)" << endl;
}
void Relatorios::imprimeEleitosPorGenero() {
    int total = this->getSistemaEleitoral()->getCandidatosEleitos().size();
    int mas = 0, fem = 0;
    for (Candidato* c : this->getSistemaEleitoral()->getCandidatosEleitos()) {
        if (c->getGenero() == HOMEM) mas++;
        else fem++;
    }

    cout << "Eleitos, por gênero:" << endl;
    cout << "Feminino:  " << fem << " (" << fixed << setprecision(2) << (100.0 * fem / total) << "%)" << endl;
    cout << "Masculino: " << mas << " (" << fixed << setprecision(2) << (100.0 * mas / total) << "%)" << endl;
}
void Relatorios::imprimePorcentagensDeVoto() {
    int total = this->getSistemaEleitoral()->getVotosNominais() + this->getSistemaEleitoral()->getVotosLegenda();

    cout << fixed << setprecision(2);
    cout << "Total de votos válidos:    " << total << endl;
    cout << "Total de votos nominais:   " << this->getSistemaEleitoral()->getVotosNominais() 
         << " (" << (100.0 * this->getSistemaEleitoral()->getVotosNominais() / total) << "%)" << endl;
    cout << "Total de votos de legenda: " << this->getSistemaEleitoral()->getVotosLegenda() 
         << " (" << (100.0 * this->getSistemaEleitoral()->getVotosLegenda() / total) << "%)" << endl;
}