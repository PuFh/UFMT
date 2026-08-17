import java.util.Scanner;

public class operacoes {
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);
        //double v1,v2;
        double resultado =0.0;

        System.out.println("Ambas as variaveis sao double!");
        System.out.println("Digite ou valor da 1 variavel: ");
        double v1 = leitor.nextDouble();
        System.out.println("Digite o valor da 2 variavel:");
        double v2 = leitor.nextDouble();

        int operacao = -1;
        while(operacao != 0){

            System.out.println("\n---OPERACOES BASICAS---\n");
            System.out.println("1. Soma");
            System.out.println("2. Subtracao");
            System.out.println("3. Divisao");
            System.out.println("4. Multiplicacao");
            System.out.println("0. Sair");
            System.out.println("\n----------------------\n");

            System.out.print("-> ");
            operacao = leitor.nextInt();

            switch (operacao) {
                case 1://SOMA
                    resultado = v1+v2;
                    System.out.printf("Valor da soma: %.2f",resultado);
                    break;
                
                case 2://SUBTRACAO
                    resultado =v1-v2;
                    System.out.printf("Valor da subtracao: %.2f",resultado);
                    break;
                case 3://DIVISAO
                    resultado = v1/v2;
                    if(v2 == 0){
                        System.out.println("a 2 varivel nao pode ser 0.");
                        break;
                    }
                    System.out.printf("Valor da Divisao: %.2f",resultado);
                    break;
                case 4://MULTIPLICACAO
                    resultado = v1*v2;
                    System.out.printf("Valor da Multiplicacao: %.2f",resultado);
                    break;
                case 0:
                    System.out.println("Saindo...\n");
                    break;
            
                default:
                    System.out.println("Opcao invalida!");
                    break;
            }
        }


    }
}
