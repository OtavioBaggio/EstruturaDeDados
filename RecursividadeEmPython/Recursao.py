import random
import time

TAM = 5000

# a - Inicialização da variável de controle;
# b - Condição de parada/continuidade;
# c - transformação da variável de controle -> ponto de recursão;

def popularR(vetor, n):
    if n > 0:
        # código antes da recursão, ou seja, no empilhamento;
        popularR(vetor, n - 1)

        # código depois da recursão, ou seja, no desempilhamento;
        vetor[n - 1] = random.randint(0, 19)

def exibirR(vetor, n):
    if n > 0:
        # código antes da recursão, ou seja, no empilhamento;
        # vetor[n - 1] = random.randint(0, 19)

        # ponto da recursão - transformação da variável de controle;
        exibirR(vetor, n - 1)

        # código depois da recursão, ou seja, no desempilhamento;
        print(vetor[n - 1])

def somarR(vetor, n):
    if n > 0:
        return vetor[n - 1] + somarR(vetor, n - 1)
    return 0

def contarElementosR(vetor, n):
    if n > 0:
        return 1 + contarElementosR(vetor, n - 1)
    return 0

def contarParesR(vetor, n):
    if n > 0:
        if vetor[n - 1] % 2 == 0:
            return 1 + contarParesR(vetor, n - 1)
        else:
            return contarParesR(vetor, n - 1)
    return 0

def menorR(vetor, n):
    if n == 1:  # ao invés de sair do vetor no empilhamento, paro na primeira posição
        return vetor[0]

    oQueVemDeCima = menorR(vetor, n - 1)
    if oQueVemDeCima < vetor[n - 1]:
        return oQueVemDeCima
    return vetor[n - 1]

def main():
    random.seed(time.time())
    vetor = [0] * TAM
    tamanhoSorteado = random.randint(5, 14)

    popularR(vetor, tamanhoSorteado)

    print("Tamanho do vetor:", contarElementosR(vetor, tamanhoSorteado))
    exibirR(vetor, tamanhoSorteado)

    print("A soma dos elementos:", somarR(vetor, tamanhoSorteado))
    print("Quantidade de pares:", contarParesR(vetor, tamanhoSorteado))
    print("Menor elemento:", menorR(vetor, tamanhoSorteado))

if __name__ == "__main__":
    main()



