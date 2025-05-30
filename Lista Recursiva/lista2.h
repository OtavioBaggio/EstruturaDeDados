typedef struct no{
    int dado;
    struct no *prox;
} Lista;

Lista *inserir(int dado, Lista *lista2){
    if(lista2 && dado >= lista2->dado){
        if(dado != lista2->dado){
            //avancar na lista
            lista2->prox = inserir(dado, lista2->prox);
        }
        return lista2;
    }else{  //cheguei no final da lista
        Lista *novo = (Lista*)malloc(sizeof(Lista));
        novo->dado = dado;
        if(lista2){
            novo->prox = lista2;
        }else{
            novo->prox = NULL;
        }
        return novo;
    }
}

void exibir(Lista *lista2){
    if(lista2){
        cout << lista2->dado << endl;
        exibir(lista2->prox);
    }
}

int contar(Lista *lista2){
    if(lista2){
        return 1 + contar(lista2->prox);
    }
    return 0;
}

Lista *localizar(int numero, Lista *lista2){
    if(lista2){
        if(numero == lista2->dado){
            return lista2;
        }
        return localizar(numero, lista2->prox);
    }
    return 0;
}
