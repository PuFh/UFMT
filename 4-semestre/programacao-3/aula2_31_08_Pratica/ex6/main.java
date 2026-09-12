package aula2_31_08_Pratica.ex6;

import java.util.ArrayList;
import java.util.Iterator;

public class main {
    public static void main(String[] args){
        ArrayList<contaBancaria> contas = new ArrayList<>();

        //Titular 1
        contaBancaria c1 =new contaBancaria();
        c1.titular = "Taina";
        c1.numero = 1265;
        c1.saldo = 1254676.46;
        //Titular 2

        contaBancaria c2 =new contaBancaria();
        c2.titular = "mauricio";
        c2.numero = 21343;
        c2.saldo = 12351.4;

        //Titular 3
        contaBancaria c3 =new contaBancaria();
        c3.titular = "Veronica";
        c3.numero = 89325;
        c3.saldo = 48.3;

        //adicionando dentro do arry
        contas.add(c1);
        contas.add(c2);
        contas.add(c3);

        double soma = 0;
        Iterator<contaBancaria> i = contas.iterator();
        while (i.hasNext()) {
            contaBancaria c = i.next();
            System.out.println("Titular: "+c.titular+"\nNumero: "+c.numero+"\nSaldo: "+c.saldo);
            System.out.println("---------\n");
            soma += c.saldo;
        }
        System.out.println("Saldo Total: "+soma);

    }
}
