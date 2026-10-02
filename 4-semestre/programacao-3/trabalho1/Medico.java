package trabalho1;

public class Medico extends Profissional {

    private static final double VALOR_PLANTAO = 400.0;
    private String especialidade;
    private int plantoes;

    public Medico(String nome, String registro, double salarioBase,
                  String especialidade, int plantoes) {
        super(nome, registro, salarioBase);
        this.especialidade = especialidade;
        this.plantoes = plantoes;
    }

    @Override
    public double calcularSalario() {
        return salarioBase + (plantoes * VALOR_PLANTAO);
    }

    @Override
    public String getProfissao() {
        return "Médico (" + especialidade + ")";
    }
}