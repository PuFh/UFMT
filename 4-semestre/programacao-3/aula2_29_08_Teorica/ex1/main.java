package aula2_29_08_Teorica.ex1;

public class main {
    public static void main(String[] args){
        Carro carro1;
        Carro carro2;

        carro1 = new Carro();
        carro2 = new Carro();

        //1 objeto instanciado
        carro1.ano = 1984;
        carro1.marca = "Honda";
        carro1.modelo = "Civic";
        carro1.exibirInfo();

        //2 objeto instanciado
        carro2.ano = 2025;
        carro2.marca = "Ford";
        carro2.modelo = "Mustang Turbo";
        carro2.exibirInfo();
    }
}
