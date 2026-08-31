package aula1_17_08_Pratica.ex5;//caminho

import java.util.Scanner;

public class primos {
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);

        int n,j;
        System.out.print("Digite o tamanho do ranged para ver os numeros primo dele(0 a n):");
        n = leitor.nextInt();

        for(int i = 2; i < n; i++){
            for(j = 2; i%j != 0; j++);//ele n ira verificar nada, apenas a divisao
            if(i == j)
                System.out.println(i);
        }


        leitor.close();
    }
}
