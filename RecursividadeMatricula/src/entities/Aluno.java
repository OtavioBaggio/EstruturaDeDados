package entities;

/**
 * Classe que representa um aluno com matrícula e nome.
 */
public class Aluno {
	private int matricula;
    private String nome;

    /**
     * Construtor da classe Aluno.
     *
     * @param matricula Número de matrícula do aluno.
     * @param nome      Nome do aluno.
     */
    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
    }

    /**
     * Retorna a matrícula do aluno.
     *
     * @return matrícula.
     */
    public int getMatricula() {
        return matricula;
    }

    /**
     * Retorna o nome do aluno.
     *
     * @return nome.
     */
    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return "Matrícula: " + matricula + " - Nome: " + nome;
    }

}
