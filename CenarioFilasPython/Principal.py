from queue import Queue
from Processo_class import Processo
import random

# Função que gera processos e os distribui nas filas
def gerar_processos_em_filas(fila_prioritaria, fila_normal, quantidade_processos):
    processos_existentes = set()  # Para evitar processos repetidos

    for _ in range(quantidade_processos):
        numero = random.randint(0, 1000)

        # 0 → atender fila prioritária
        if numero == 0:
            if not fila_prioritaria.empty():
                print("ATENDENDO:", fila_prioritaria.get())
            else:
                print("Fila prioritária vazia")
        # 500 → atender fila normal
        elif numero == 500:
            if not fila_normal.empty():
                print("ATENDENDO:", fila_normal.get())
            else:
                print("Fila normal vazia")
        else:
            # Criar processo dependendo do número
            if numero < 500:
                processo = Processo(numero, "Processo de alta prioridade")
                if processo not in processos_existentes:
                    fila_prioritaria.put(processo)
                    processos_existentes.add(processo)
                    print("INSERIDO:", processo)
            else:
                processo = Processo(numero, "Processo normal")
                if processo not in processos_existentes:
                    fila_normal.put(processo)
                    processos_existentes.add(processo)
                    print("INSERIDO:", processo)

# Exibir processos que restaram nas filas
def exibir_processos_nao_atendidos(fila, nome_fila):
    print("\n", nome_fila.upper())
    print("Total de processos não atendidos:", fila.qsize())
    while not fila.empty():
        print(fila.get())

# Função principal
def main():
    # Criando duas filas do tipo Queue
    fila_prioritaria = Queue()
    fila_normal = Queue()

    # Gerando 10.000 processos
    gerar_processos_em_filas(fila_prioritaria, fila_normal, 498)

    # Exibindo o que sobrou
    exibir_processos_nao_atendidos(fila_prioritaria, "Fila Prioritária")
    exibir_processos_nao_atendidos(fila_normal, "Fila Normal")

if __name__ == "__main__":
    main()
