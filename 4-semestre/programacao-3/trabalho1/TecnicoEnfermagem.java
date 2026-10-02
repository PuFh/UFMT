package trabalho1;

public class TecnicoEnfermagem extends Profissional {

    private static final double ADICIONAL_INSALUBRIDADE = 0.15;

    public TecnicoEnfermagem(String nome, String registro, double salarioBase) {
        super(nome, registro, salarioBase);
    }

    @Override
    public double calcularSalario() {
        return salarioBase + (salarioBase * ADICIONAL_INSALUBRIDADE);
    }

    @Override
    public String getProfissao() {
        return "Técnico de Enfermagem";
    }
}
