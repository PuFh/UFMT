package aula2_31_08_Pratica.ex5;

import java.lang.classfile.constantpool.PoolEntry;

public class main {
    public static void main(String[] args){
        Produto p1 = new Produto();
        Produto p2 = new Produto();

        //instanciando p1
        p1.id = 1234;
        p1.nome = "Shaampo";
        p1.preco = 17.4;
        //instanciando p2
        p2.id = 8902;
        p2.nome = "Condicionador";
        p2.preco = 22.75;

        p1.exibirDetalhes();
        p2.exibirDetalhes();

        //aplicando desconto
        p1.aplicarDesconto(10);
        p2.aplicarDesconto(15);

        p1.exibirDetalhes();
        p2.exibirDetalhes();
    }
}
