#include <iostream>
#include <ctime>
#include <cstdlib>

#define TAM 5000

using namespace std;

// a - Inicializa��o da vari�vel de controle;
// b - Condi��o de parada/continuidade;
// c - transforma��o da vari�vel de controle -> ponto de recurs�o;

void popularR(int vetor[], int n) {
    if (n > 0) {
        //c�digo antes da recurs�o, ou seja, no empilhamento;
        popularR(vetor, n - 1);

        //c�digo depois da recurs�o, ou seja, no desempilhamento;
        vetor[n - 1] = rand() % 20;
    }
}

void exibirR(int vetor[], int n) {
    if (n > 0) {
        //c�digo antes da recurs�o, ou seja, no empilhamento;
        //vetor[n - 1] = rand() % 20;

        //ponto da recurs�o - transforma��o da vari�vel de controle;
        exibirR(vetor, n - 1);

        //c�digo depois da recurs�o, ou seja, no desempilhamento;
        cout << vetor[n - 1] << "\n";
    }
}

int somarR(int vetor[], int n) {
    if (n > 0) {
        return vetor[n - 1] + somarR(vetor, n - 1);
    }
    return 0;
}

int contarElementosR(int vetor[], int n) {
    if (n > 0) {
        return 1 + contarElementosR(vetor, n - 1);
    }
    return 0;
}

int contarParesR(int vetor[], int n) {
    if (n > 0) {
        if (vetor[n - 1] % 2 == 0) {
            return 1 + contarParesR(vetor, n - 1);
        } else {
            return 0 + contarParesR(vetor, n - 1);
        }
    }
    return 0;
}

int menorR(int vetor[], int n) {
    if (n == 1) {  //ao inv�s de sair do vetor no empilhamento, paro na primeira posi��o
        return vetor[0];
    }

    int oQueVemDeCima = menorR(vetor, n - 1);
    if (oQueVemDeCima < vetor[n - 1]) {
        return oQueVemDeCima;
    }
    return vetor[n - 1];
}

int main() {
    srand(time(NULL));
    int vetor[TAM];
    int tamanhoSorteado = rand() % 10 + 5;

    popularR(vetor, tamanhoSorteado);

    cout << "Tamanho do vetor: " << contarElementosR(vetor, tamanhoSorteado) << endl;
    exibirR(vetor, tamanhoSorteado);

    cout << "A soma dos elementos: " << somarR(vetor, tamanhoSorteado) << endl;
    cout << "Quantidade de pares: " << contarParesR(vetor, tamanhoSorteado) << endl;
    cout << "Menor elemento: " << menorR(vetor, tamanhoSorteado) << endl;

    return 0;
}
