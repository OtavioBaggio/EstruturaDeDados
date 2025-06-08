#include <iostream>
#include <cstdlib>

using namespace std;

#include "arvore.h"

int main() {

    Arvore *arvore = NULL;

    //Inserindo elementos na árvore:
    arvore = inserir(50, arvore);
    arvore = inserir(35, arvore);
    arvore = inserir(40, arvore);
    arvore = inserir(60, arvore);
    arvore = inserir(80, arvore);

    //Exibindo os métodos:
    exibirOrdenado(arvore);
    cout << endl;

    cout << "Total de elementos: " << contar(arvore) << endl;

    cout << "Elementos somados: " << somar(arvore) << endl;

    cout << "Elementos pares: " << contarPares(arvore) << endl;

    cout << "Folhas: ";
    exibirFolhas(arvore);
    cout << endl;

    cout << "Total de folhas: " << contarFolhas(arvore) << endl;

    return 1;

}

