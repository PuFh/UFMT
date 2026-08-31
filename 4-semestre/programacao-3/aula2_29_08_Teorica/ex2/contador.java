package aula2_29_08_Teorica.ex2;

public class contador {
    static int totalObjetos = 0;

    static void mostrarTotal(){
        System.out.println(totalObjetos);
    }

    public contador(){
        contador.totalObjetos++;
    }
}
