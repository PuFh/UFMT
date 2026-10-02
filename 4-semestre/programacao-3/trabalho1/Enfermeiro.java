package trabalho1;

public class Enfermeiro extends Profissional {

    private static final double ADICIONAL_NOTURNO = 0.20;
    private boolean turnoNoturno;

    public Enfermeiro(String nome, String registro, double salarioBase,
                      boolean turnoNoturno) {
        super(nome, registro, salarioBase);
        this.turnoNoturno = turnoNoturno;
    }

    @Override
    public double calcularSalario() {
        if (turnoNoturno) {
            return salarioBase + (salarioBase * ADICIONAL_NOTURNO);
        }
        return salarioBase;
    }

    @Override
    public String getProfissao() {
        return "Enfermeiro";
    }
}