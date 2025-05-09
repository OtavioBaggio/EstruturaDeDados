#include <iostream>
#include <ctime>
#include <cstdlib>

#define TAM 5000

using namespace std;

// a - Inicialização da variável de controle;
// b - Condição de parada/continuidade;
// c - transformação da variável de controle -> ponto de recursão;

void popularR(int vetor[], int n) {
    if (n > 0) {
        //código antes da recursão, ou seja, no empilhamento;
        popularR(vetor, n - 1);

        //código depois da recursão, ou seja, no desempilhamento;
        vetor[n - 1] = rand() % 20;
    }
}

void exibirR(int vetor[], int n) {
    if (n > 0) {
        //código antes da recursão, ou seja, no empilhamento;
        //vetor[n - 1] = rand() % 20;

        //ponto da recursão - transformação da variável de controle;
        exibirR(vetor, n - 1);

        //código depois da recursão, ou seja, no desempilhamento;
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
    if (n == 1) {  //ao invés de sair do vetor no empilhamento, paro na primeira posição
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
