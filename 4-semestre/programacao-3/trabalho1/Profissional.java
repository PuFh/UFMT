package trabalho1;

public abstract class Profissional {

    private String nome;
    private String registro;
    protected double salarioBase;

    public Profissional(String nome, String registro, double salarioBase) {
        if (salarioBase < 0) {
            throw new IllegalArgumentException("Salário base não pode ser negativo.");
        }
        this.nome = nome;
        this.registro = registro;
        this.salarioBase = salarioBase;
    }

    public String getNome() {
        return nome;
    }

    public String getRegistro() {
        return registro;
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public abstract double calcularSalario();

    public abstract String getProfissao();
}