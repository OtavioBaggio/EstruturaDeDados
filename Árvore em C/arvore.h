#include <iostream>
#include <cstdlib>
using namespace std;

//Estrutura com os dados necessarios para manipular a �rvore:
typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} Arvore;

//Inserindo na �rvore:
Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {   //percurso pr�-fixado ou RED
        //percorrer ou pra esquerda ou pra direita
        if (valor < raiz->dado) {
            //ir para esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else {
            //ir para direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;
    } else {
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

//Exibi a �rvore do menor para o maior:
void exibirOrdenado(Arvore *raiz) {
    if (raiz) {   // percurso in-fixado ou ERD
        exibirOrdenado(raiz->esq);
        cout << raiz->dado << "\t";
        exibirOrdenado(raiz->dir);
    }
}

//Conta os elementos:
int contar(Arvore *raiz) {
    if (raiz) {
        return 1 + contar(raiz->esq) + contar(raiz->dir);
    }
    return 0;
}

//Soma os elementos:
int somar(Arvore *raiz) {
    if (raiz) {
        return raiz->dado + somar(raiz->esq) + somar(raiz->dir);
    }
    return 0;
}

//Conta os pares da �rvore:
int contarPares(Arvore *raiz) {
    if (raiz) {
        if (raiz->dado % 2 == 0) {
            return 1 + contarPares(raiz->esq) + contarPares(raiz->dir);
        }
        return 0 + contarPares(raiz->esq) + contarPares(raiz->dir);
    }
    return 0;
}

//Mostra as folhas da �rvore:
void exibirFolhas(Arvore *raiz) {
    if (raiz) {
        // if(!raiz->esq && !raiz->dir)
        if (raiz->esq == NULL && raiz->dir == NULL) {
            cout << raiz->dado << "\t";
        }
        exibirFolhas(raiz->esq);
        exibirFolhas(raiz->dir);
    }
}

//Conta as folhas:
int contarFolhas(Arvore *raiz) {
    if (raiz) {
        // if(!raiz->esq && !raiz->dir)
        if (raiz->esq == NULL && raiz->dir == NULL) {
            return 1;
        }
        return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
    }
    return 0;
}

//Localiza na �rvore:
bool localizar(int valor, Arvore *raiz) {
    if (!raiz) {    //  ' == NULL '
        return false;   //Caso a �rvore esteja vazia ou o valor n�o seja encontrado
    }
    if (valor == raiz->dado) {
        return true;    // Encontrou o valor
    } else if (valor < raiz->dado) {
        // Se o valor for menor, vai para a sub�rvore esquerda
        return localizar(valor, raiz->esq);
    } else {
        // Se o valor for maior, vai para a sub�rvore direita
        return localizar(valor, raiz->dir);
    }
}

