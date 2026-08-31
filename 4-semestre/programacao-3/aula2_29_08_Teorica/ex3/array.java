package aula2_29_08_Teorica.ex3;
//bibliotecas necessarias
import java.util.ArrayList;
import java.util.Iterator;

public class array {
    public static void main(String[] args){
        ArrayList<String> alunos = new ArrayList<>();

        alunos.add("Matheus");
        alunos.add("Taina");
        alunos.add("Victor");
        alunos.add("isabela");
        alunos.add("Sofia");

        Iterator i = alunos.iterator();
        while (i.hasNext()){
            System.out.println("Aluno: "+i.next());
        }
    }
}
