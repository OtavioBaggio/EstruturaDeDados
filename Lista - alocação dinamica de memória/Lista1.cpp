#include <iostream>
using namespace std;

#include "lista.h"

int main(){
    Celula *lista = NULL;

    lista = inserir(7, lista);
    lista = inserir(10, lista);
    lista = inserir(5, lista);
    lista = inserir(10, lista);
    lista = inserir(70, lista);
    lista = inserir(12, lista);
    lista = inserir(55, lista);

    cout << "A lista contem: " << contarLista(lista) << " elementos\n";

    exibir(lista);

    int numero;
    cout << "Digite numero para pesquisa: ";
    cin >> numero;

    cout << numero << " esta na lista? " << estaNaLista(numero, lista) << endl;

    //contar ocorrencias de um numero:
    cout << numero << " aparece na lista: " << contarOcorrencia(numero, lista) << " vez(es)\n";

    //verificar se a lista esta ou n�o ordenada:
    cout << "A lista esta ordenada? " << (verificaOrdenacao(lista) ? "sim" : "nao") << endl;

    //calcular a m�dia do elementos da lista:
    cout << "A media dos numeros contidos na lista e de: " << calcularMedia(lista) << endl;

    //Criar um m�todo de ordena��o da lista encadeada:
    lista = ordenarLista(lista);
    cout << "\nlista ordenada:\n";
    exibir(lista);


    return 1;
}
