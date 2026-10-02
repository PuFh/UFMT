package trabalho1;

public class Fisioterapeuta extends Profissional {

    private static final double VALOR_ATENDIMENTO = 35.0;
    private int atendimentos;

    public Fisioterapeuta(String nome, String registro, double salarioBase,
                          int atendimentos) {
        super(nome, registro, salarioBase);
        this.atendimentos = atendimentos;
    }

    @Override
    public double calcularSalario() {
        return salarioBase + (atendimentos * VALOR_ATENDIMENTO);
    }

    @Override
    public String getProfissao() {
        return "Fisioterapeuta";
    }
}
