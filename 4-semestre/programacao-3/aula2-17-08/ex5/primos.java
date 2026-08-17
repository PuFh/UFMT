import java.util.Scanner;

public class primos {
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);

        int n;


        System.out.print("Digite o o invervalo que deseja (0 a N): ");
        n = leitor.nextInt();
        int i =1;
        int j =1;
        int primo = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= i; j++){
                if(i/j ==1){
                    primo = 1
                    System.out.println();
                }
            }

        }
        leitor.close();
    }
}
