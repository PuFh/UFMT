import java.util.Scanner;

public class primos {
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);

        int n;
        int j;
        System.out.print("Digite o tamanho do ranged para ver os numeros primo dele(0 a n):");
        n = leitor.nextInt();

        for(int i = 2; i < n; i++){
            for(j = 2; i%j != 0; j++){
                
            }
            if(i == j)
                System.out.println(i);
        }


        leitor.close();
    }
}
