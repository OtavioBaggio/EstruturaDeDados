package Main;

import java.util.ArrayList;
import java.util.Random;

import entities.Aluno;

/*
 		EXERCÍCIO - RECURSIVIDADE - ESTRUTURA DE DADOS
 criar um método recursivo que exibe somente os números pares
 criar um código java com lista recursiva
 esta lista deve armazenar objetos do tipo aluno com matricula e nome..... contudo, o número de matrícula deve ser sorteado
 uma vez que o aluno com matricula e nome for gerado, armazenar em uma lista..... esta rotina deve estar em um método recursivo
 
 */

/**
 * Classe principal que gerencia uma lista de alunos usando recursão.
 */
public class ListaRecursivaAlunos {
	private static final Random GERADOR = new Random();

    /**
     * Preenche recursivamente uma lista com alunos, cada um com uma matrícula aleatória.
     *
     * @param lista     Lista de alunos a ser preenchida.
     * @param tamanho   Quantidade de alunos a adicionar.
     * @param contador  Número usado para gerar o nome do aluno.
     */
    public static void preencherLista(ArrayList<Aluno> lista, int tamanho, int contador) {
        if (tamanho > 0) {
            int matricula = GERADOR.nextInt(100); //matrícula aleatória entre 0 e 99
            String nome = "Aluno" + contador;
            lista.add(new Aluno(matricula, nome));
            preencherLista(lista, tamanho - 1, contador + 1);
        }
    }

    /**
     * Exibe recursivamente os alunos com matrícula par.
     *
     * @param lista  Lista de alunos.
     * @param indice Índice atual da recursão.
     */
    public static void exibirMatriculasPares(ArrayList<Aluno> lista, int indice) {
        if (indice < lista.size()) {
            Aluno aluno = lista.get(indice);
            if (aluno.getMatricula() % 2 == 0) {
                System.out.println(aluno);
            }
            exibirMatriculasPares(lista, indice + 1);
        }
    }


    /**
     * Método principal que executa o programa.
     *
     * @param args Argumentos da linha de comando (não utilizados).
     */
    public static void main(String[] args) {
    	ArrayList<Aluno> lista = new ArrayList<>();
        preencherLista(lista, 10, 1);      //Preenche com 10 alunos
        System.out.println("Alunos com matrícula par:");
        exibirMatriculasPares(lista, 0);   //Exibe os alunos com matrícula par
		

	}

}
