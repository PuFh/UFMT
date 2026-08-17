public class ex1 {
    public static void main(String[] args){
        int fibonacci[] = new int[30];
        //os 2 primeiros elementos inicializados
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        int indice = 2; //ponto de partida

        //atribuicao dos valores
        for(int i = indice; i < 30; i++){
            fibonacci[indice] = fibonacci[indice-2] + fibonacci[indice-1];
            indice++;
        }
        //leitura
        for(int i = 0; i < 30; i++){
            System.out.println(fibonacci[i]);;
        }
    }
}