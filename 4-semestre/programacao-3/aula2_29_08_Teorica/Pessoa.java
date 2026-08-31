package aula2_29_08_Teorica;

import java.lang.String;
public class Pessoa {
        String nome;
        int id;
        String cidade;
        char genero;

        String getNome(String n){   return nome;} //n eh usado pois vc instancia os atributos diretamente na main
        int getId(int id){  return id;}

        void apresentar(){
            System.out.println("Nome: "+nome+"\nId: "+id+"\nCidade: "+cidade+"\nGenereo: "+genero);
        }
}
