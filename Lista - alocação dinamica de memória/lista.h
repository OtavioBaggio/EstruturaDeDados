#include <cstdlib>

typedef struct no{
    int dado;
    struct no *prox;
}Celula;

Celula *inserir(int dado, Celula *lista);
void exibir(Celula *lista);
int contarLista(Celula *lista);
bool estaNaLista(int dado, Celula *lista);
int contarOcorrencia(int dado, Celula *lista);
bool verificaOrdenacao(Celula *lista);
float calcularMedia(Celula *lista);
Celula* ordenarLista(Celula *lista);

Celula *inserir(int dado, Celula *lista){

    if (estaNaLista(dado, lista)) {
        cout << "Valor duplicado: " << dado << " nao sera inserido na lista.\n";
        return lista;
    }

    //alocar memória:
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores que vem do parâmetro:
    novo->dado = dado;
    novo->prox = NULL;

    //testar se é o primeiro elemento a ser inserido:
    if(!lista){     // mesma coisa que: if(lista == NULL)
        return novo;
    }

    //percorrer a estrutura até o final:
    Celula *p;
    for(p = lista; p->prox != NULL; p = p->prox);

    //encadear e retornar:
    p->prox = novo;
    return lista;

}

void exibir(Celula *lista){
    for(Celula *p = lista; p != NULL; p = p->prox){
        cout << p->dado << "\t";
    }
    cout << endl;
}

int contarLista(Celula *lista){
    int total = 0;
    for(Celula *p = lista; p != NULL; p = p->prox){
        total++;
    }
    return total;
}

//Verificando se está na lista:
bool estaNaLista(int dado, Celula *lista){
    for(Celula *p = lista; p != NULL; p = p->prox){
        if(dado == p->dado){
            return true; //1 para sim
        }
    }
    return false;  //0 ou não localizado
}

//Verifica QUANTAS vezes aparece na lista:
int contarOcorrencia(int dado, Celula *lista){
    int cont = 0;
    for(Celula *p = lista; p != NULL; p = p->prox){
        if(p->dado == dado){
            cont++;
        }
    }
    return cont;
}

//verificar se a lista esta ou não ordenada:
bool verificaOrdenacao(Celula *lista) {
    if (!lista || !lista->prox) {
        return true; // lista vazia ou com 1 elemento está ordenada
    }

    for (Celula *p = lista; p->prox != NULL; p = p->prox) {
        if (p->dado > p->prox->dado) {
            return false; // encontrou um fora de ordem
        }
    }
    return true; // percorreu tudo, está ordenada
}

//calcular a média do elementos da lista:
float calcularMedia(Celula *lista){
    if(!lista){
        return 0;
    }

    int soma = 0;
    int total = 0;
    for(Celula *p = lista; p != NULL; p = p->prox){
        soma += p->dado;
        total++;
    }
    return (float)soma / total;  //retorna a media
}

//alterar o inserir para que controle duplicados - ou seja, proiba cadastro de replicado:
Celula* ordenarLista(Celula *lista){
    if(!lista || !lista->prox){
        return lista;
    }
    for(Celula *k = lista; k != NULL; k = k->prox){
        for(Celula *j = lista; j != NULL; j = j->prox){
            if(k->dado > j->dado){
                int tmp = k->dado;
                k->dado = j->dado;
                j->dado = tmp;
            }
        }
    }
    return lista;
}


