package aula2_29_08_Teorica;

public class main {
    public static void main(String[] args){
        Pessoa pessoa1;

        //pessoa1.apresentar();
        pessoa1 = new Pessoa();
        pessoa1.nome = "Joao";
        pessoa1.id = 120947;
        pessoa1.cidade = "Cuiaba";
        pessoa1.genero = 'M';

        pessoa1.apresentar();
    }
}
