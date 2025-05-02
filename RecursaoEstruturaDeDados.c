/*      QUESTOES SOBRE RECURSAO - ESTRUTURA DE DADOS

1)O que � e para que serve recurs�o?
    R:
      T�cnica para repetir instru��es, que substitui as instru��es de controle, como o for e o while.
      Um m�todo que chama ele mesmo gerando um empilhamento de processos;

2)O programador, ao fazer um m�todo recursivo, precisa garantir 3 situa��es. Quais?
    R:
    Inicializar a vari�vel de controle;
    Teste de parada da repeti��o;
    Transforma��o da vari�vel de controle;

3)Em que momento no c�dgio exemplo o empilhamento acontece? Como � poss�vel visualizar isso no c�digo?

void mostraPares(int *v, int n){
    if(n > 0){
      if(v[n - 1] % 2 == 0) printf("%d\n", v[n - 1]);
      mostraPares(v, n - 1);
    }
}
    R:
    Acontece na linha: mostraPares(v, n - 1);
    Cada vez que essa linha � executada, uma nova chamada da fun��o � feita com um valor de n  menor;
    Cada chamada ainda n�o terminou quando a pr�xima � feita, ent�o elas ficam empilhadas na mem�ria;
    Podemos visualizar isso observando o comportamento recursivo, at� ser 0;

4)Imagine o m�todo recursivo contaPares(). Ele deve contar os n�meros pares de um vetor de inteiros de tamanho n.
  - quais seriam os paramentros do m�todo?
  - qual seria a vari�vel de controle?
  - no c�digo do m�todo, como seria a chamada do m�todo para garantir a recurs�o?

int contaPares(int *v, int n){
  if(n > 0){
    if(v[n - 1] % 2 == 0){
      return 1 + contaPares(v, n - 1);
    } /*else*/      /*
    return 0 + contaPares(v, n - 1);
  }
  return 0;
}

    R:
    int *v -> ponteiro para o vetor inteiros;
    int n -> tamanho atual do vetor / posi��o que est� sendo analisada;
    R:
    A vari�vel de controle � a n, ela vai determinar se a recurs�o continua e qual elemento est� verificando;
    R:
    contaPares(v, n - 1);

5)Imagine um m�todo recursivo contaPares(). Contudo, vai contar os n�meros de uma lista encadeada simples.
  - Qual � o parametro?
  - Qual � o tipo de retorno do m�todo?
  - E qual seria a vari�vel de controle e no c�digo do m�todo e como seria a chamada do m�otodo para garantir a recurs�o?

int contaPares(Celula *l){ //variavel de controle o l
  if(l){  //criterio de parada
    if(l->dado % 2 ==0){
      return 1 + contaPares(l->prox);
    } /*else*/      /*
    return 0 + contaPares(l->prox);
  }
  return 0;
}

    R:
    O paramentro � um ponteiro (Celula *l);
    R:
    o tipo de retorno � int;
    R:
    A vari�vel de controle � l, e a chamada: contaPares(l->prox);

*/

#include <stdio.h>
#include <locale.h>

//6) Implemente um m�todo recursivo que exibe primeiro todos os pares da lista encadeada e, depois, todos os impares da mesma lista.

typedef struct celula {
    int dado;
    struct celula *prox;
} Celula;

void exibeParesDepoisImpares(Celula *l) {
    if (l) {
        if (l->dado % 2 == 0)
            printf("%d\n", l->dado);
        exibeParesDepoisImpares(l->prox);
    }
}

void exibeImparesDepoisPares(Celula *l) {
    if (l) {
        if (l->dado % 2 != 0)
            printf("%d\n", l->dado);
        exibeImparesDepoisPares(l->prox);
    }
}

void exibeParesEImpares(Celula *l) {
    exibeParesDepoisImpares(l);
    exibeImparesDepoisPares(l);
}


int main(){
setlocale(LC_ALL, "portuguese");

    Celula a = {1, NULL};
    Celula b = {4, &a};
    Celula c = {3, &b};
    Celula d = {2, &c};

    Celula *lista = &d;

    exibeParesEImpares(lista);



return 0;
}
