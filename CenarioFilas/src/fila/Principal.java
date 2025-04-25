package fila;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

/*
CENÁRIO DE APLICAÇÃO DE FILAS:
	1) gerenciar processos -> id, descrição
	    - classe Processo
		atributos -> id, descrição
		metodos -> toString, equals
	2) processos tem prioridades -> processos com id entre 1 e 500 tem alta prioridade e processos entre 501 e 1000 tem baixa prioridade
	3) há duas filas -> normal (processos entre 501 e 1000) e prioritária (processos entre 1 a 500)
	4) dinâmica:
	    - um número aleatório entre 0 e 1000
		- 0 -> atender/remover a cabeça da fila de prioridade - tratar quando vazia
		- 500 -> atender/remover a cabeça da fila normal - tratar quando vazia
		- demais números seguem a dinâmica acima -> controle de replicados
	    - a dinâmica deve repetir 10000
	    - exibir as filas ao final, com os processos não atendidos (mostrando contadores)
*/

public class Principal {
	
	/***
	 * método estático ou de classe responsável por gerar processos aleatórios entre 1 a 1000
	 * distribuindo em duas filas
	 * @param filaPrioritaria - fila prioritaria(números abaixo de 500)
	 * @param filaNormal - fila normal(números acima de 500)
	 * @param quantidadeProcessos
	 */
	
	public static void gerarProcessosEmFilas(Queue<Processo> filaPrioritaria, Queue<Processo> filaNormal, int quantidadeProcessos) {
		Random gerador = new Random();
		int numeroProcessoGerado;
		
		//rotina para gerar 10000
		for(int i = 0; i < quantidadeProcessos; i++) {
			numeroProcessoGerado = gerador.nextInt(0, 1001);
			
			switch (numeroProcessoGerado) {
			case 0:
				//rotina para retirar da fila prioritária
				System.out.println("ATENDENDO: " + filaPrioritaria.poll());
				break;
			case 500:
				//rotina para retirar da fila normal
				System.out.println("ATENDENDO: " + filaNormal.poll());

			default:
				//rotina para inserir processo na fila de prioridade:
				if(numeroProcessoGerado < 500) {
					Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de alta prioridade");
					if(!filaPrioritaria.contains(processoTmp)) {
						filaPrioritaria.offer(processoTmp); //filaPrioritaria.add(tmp);
						System.out.println(processoTmp);
					}
				//rotina para inserir processo na fila normal:	
				}else {
					Processo processoTmp = new Processo(numeroProcessoGerado, "Processo normal");
					if(!filaNormal.contains(processoTmp)) {
						filaNormal.offer(processoTmp); //filaPrioritaria.add(tmp);
						System.out.println(processoTmp);
					}
					
				}
				break;
			}
		}
	}
	
	/***
	 * método estático que exibe processos existentes em fila
	 * @param fila - contem uma fila normal ou prioritaria
	 * @param frase - texto a ser exibido no cabeçalho da exibição ou listagem
	 */
	
	public static void exibirProcessosNaoAtendidos(Queue<Processo> fila, String frase) {
		System.out.println(frase);
		System.out.println("Total de processos não atendidos: " + fila.size());
		
		for(Processo processo : fila) {
			System.out.println(processo);
		}
	}

	public static void main(String[] args) {
		
		
		
		Queue<Processo> filaPrioritaria = new LinkedList<>();
		Queue<Processo> filaNormal = new LinkedList<>();
		
		gerarProcessosEmFilas(filaPrioritaria, filaNormal, 1000);
		
		exibirProcessosNaoAtendidos(filaPrioritaria, "Fila prioritária");
		exibirProcessosNaoAtendidos(filaNormal, "Fila normal");
		
		

	}

}
