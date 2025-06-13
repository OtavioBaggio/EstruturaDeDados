#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "arvore.h"

int main() {
    Arvore *arvore = NULL;
    int qtd = 10;
    int numero;

    srand(time(NULL));

    for (; qtd > 0; qtd--) {
        numero = rand() % 10;
        cout << "Numero gerado: " << numero << endl;
        arvore = inserir(numero, arvore);
    }

    cout << endl;
    cout << "Total de nos: " << contarNodos << endl;
    exibirArvore(0, arvore);

    /*
    cout << "Digite numero para pesquisa/delecao: ";
    cin >> numero;

    cout << "Localizado ? " << localizar(numero, arvore) << endl;

    cout << "Nivel Localizado ? " << localizarNivel(numero, arvore) << endl;


    cout << "Total de folhas: " << contarFolhas << endl;
    exibirFolhas(arvore);
    */

    cout << "Digite um numero: ";
    cin >> numero;

    arvore = remover(numero, arvore);

    cout << "Total de nos apos remocao: " << contarNodos(arvore) << endl;
    exibirArvore(0, arvore);

    cout << endl;

    return 1;
}
