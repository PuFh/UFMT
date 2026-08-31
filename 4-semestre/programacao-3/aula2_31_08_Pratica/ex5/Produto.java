package aula2_31_08_Pratica.ex5;

public class Produto {
    int id;
    String nome;
    double preco;

    double aplicarDesconto(double porcentagem){
        return preco = preco - (preco*(porcentagem/100));
    }
    void exibirDetalhes(){
        System.out.println("ID: "+id);
        System.out.println("Nome: "+nome);
        System.out.printf("Preco: %.2f\n",preco);
        System.out.println("----------");
    }
}
