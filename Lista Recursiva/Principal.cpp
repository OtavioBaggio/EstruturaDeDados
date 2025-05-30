#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "lista2.h"

int main(){
    srand(time(NULL));
    Lista *lista = NULL;
    for(int i = 0; i < 50; i++){
        lista = inserir(rand() % 100, lista);
    }
    cout << "Total de elementos: " << contar(lista) << endl;
    exibir(lista);

    int numero;
    cout << "Numero para pesquisa: ";
    cin >> numero;

    Lista *resposta = localizar(numero, lista);
    if(resposta){
        cout << resposta->dado << " : " << resposta << " localizado\n";
    }else{
        cout << numero << " nao localizado\n";
    }
    return 1;
}
