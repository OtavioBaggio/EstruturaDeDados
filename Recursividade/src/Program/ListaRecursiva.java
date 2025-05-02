package Program;

import java.util.ArrayList;
import java.util.Random;

public class ListaRecursiva {
	static Random gerador = new Random();
	static int numero;
	
	//Função recursiva que preenche a lista com tamanho números aleatórios e não repetidos:
	public static void popularR(ArrayList<Integer> lista, int tamanho) {
		if(tamanho > 0) {   //Critério para recursão PARAR;
			numero = gerador.nextInt(20);  //Gera número aleatório entre 0 e 19;
			
			//Verifica se o número ainda não está na lista para evitar duplicados. Se não estiver, adiciona.
			if(!lista.contains(numero)) {
				lista.add(numero);
			}
			popularR(lista, tamanho - 1);  //Chamada recursiva, diminuindo o tamanho em 1
		}
	}
	
	public static void exibir(ArrayList<Integer> lista) {
		for(Integer numero : lista) {
			System.out.println(numero + "\t");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		ArrayList<Integer> lista = new ArrayList<>();
		
		popularR(lista, 10);  //Preenche com até 10 números aleatórios
		exibir(lista);	      //Mostra os números gerados

	}

}
