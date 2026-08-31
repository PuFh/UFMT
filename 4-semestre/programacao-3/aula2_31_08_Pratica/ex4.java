package aula2_31_08_Pratica;

import java.util.Locale;
import java.util.Scanner;
public class ex4 {
    public static void main(String[] args){
        String frase;

        Scanner leitura = new Scanner(System.in);

        System.out.print("Digite a sua Frase: ");
        frase = leitura.nextLine();

        //frase base
        System.out.println(frase);
        //remocao de espacos do comeco e final
        frase = frase.trim();
        System.out.println(frase);
        //tamanho da frase
        System.out.println("Tamanho da frase: "+frase.length());
        //frase em CapsLock
        System.out.println("Tamanho da frase: "+frase.toUpperCase());
        frase = frase.replace("Java", "Linguagem java");
        System.out.println(frase);
        System.out.println(frase.charAt(5));


    }
}
