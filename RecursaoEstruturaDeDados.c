/*      QUESTOES SOBRE RECURSAO - ESTRUTURA DE DADOS

1)O que é e para que serve recursão?
    R:
      Técnica para repetir instruções, que substitui as instruções de controle, como o for e o while.
      Um método que chama ele mesmo gerando um empilhamento de processos;

2)O programador, ao fazer um método recursivo, precisa garantir 3 situações. Quais?
    R:
    Inicializar a variável de controle;
    Teste de parada da repetição;
    Transformação da variável de controle;

3)Em que momento no códgio exemplo o empilhamento acontece? Como é possível visualizar isso no código?

void mostraPares(int *v, int n){
    if(n > 0){
      if(v[n - 1] % 2 == 0) printf("%d\n", v[n - 1]);
      mostraPares(v, n - 1);
    }
}
    R:
    Acontece na linha: mostraPares(v, n - 1);
    Cada vez que essa linha é executada, uma nova chamada da função é feita com um valor de n  menor;
    Cada chamada ainda não terminou quando a próxima é feita, então elas ficam empilhadas na memória;
    Podemos visualizar isso observando o comportamento recursivo, até ser 0;

4)Imagine o método recursivo contaPares(). Ele deve contar os números pares de um vetor de inteiros de tamanho n.
  - quais seriam os paramentros do método?
  - qual seria a variável de controle?
  - no código do método, como seria a chamada do método para garantir a recursão?

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
    int n -> tamanho atual do vetor / posição que está sendo analisada;
    R:
    A variável de controle é a n, ela vai determinar se a recursão continua e qual elemento está verificando;
    R:
    contaPares(v, n - 1);

5)Imagine um método recursivo contaPares(). Contudo, vai contar os números de uma lista encadeada simples.
  - Qual é o parametro?
  - Qual é o tipo de retorno do método?
  - E qual seria a variável de controle e no código do método e como seria a chamada do méotodo para garantir a recursão?

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
    O paramentro é um ponteiro (Celula *l);
    R:
    o tipo de retorno é int;
    R:
    A variável de controle é l, e a chamada: contaPares(l->prox);

*/

#include <stdio.h>
#include <locale.h>

//6) Implemente um método recursivo que exibe primeiro todos os pares da lista encadeada e, depois, todos os impares da mesma lista.

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
