package trabalho1;

import java.util.ArrayList;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        // Lista polimórfica: guarda qualquer subclasse de Profissional
        ArrayList<Profissional> profissionais = new ArrayList<>();

        profissionais.add(new Medico("Dr. Carlos", "CRM-1234", 8000, "Cardiologia", 5));
        profissionais.add(new Enfermeiro("Ana", "COREN-5678", 4000, true));
        profissionais.add(new TecnicoEnfermagem("João", "COREN-9012", 2500));
        profissionais.add(new Fisioterapeuta("Marina", "CREFITO-3456", 3500, 40));

        // Testando a exceção do construtor
        try {
            profissionais.add(new TecnicoEnfermagem("Erro", "COREN-0000", -100));
        } catch (IllegalArgumentException e) {
            System.out.println("Erro ao cadastrar: " + e.getMessage());
        }

        System.out.println("=== Folha de pagamento do hospital ===");

        Iterator<Profissional> it = profissionais.iterator();
        while (it.hasNext()) {
            Profissional p = it.next();
            // calcularSalario() chama a versão da subclasse (polimorfismo)
            System.out.printf("Nome: %s | Profissão: %s | Salário final: R$ %.2f%n",
                    p.getNome(), p.getProfissao(), p.calcularSalario());
        }
    }
}