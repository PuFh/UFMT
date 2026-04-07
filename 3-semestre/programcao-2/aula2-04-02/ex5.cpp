#include <iostream>
#include <string>

#define TAM 3

int main(){
    std::string nome;
    int idade, i;
    float notas[TAM],media;

    printf("Nome: ");
    std::getline(std::cin, nome);

    printf("Idade: ");
    scanf("%d",&idade);

    //calculo da media
    media = 0.0;
    for(i = 0; i < TAM;i++){
        printf("Nota %d: ",i+1);
        scanf("%f",&notas[i]);

        media += notas[i];
    }
    i =0;
    media = media/3;

    printf("------INFORMACOES------\n");
    printf("Nome: %s\n",nome.c_str());
    printf("Idade: %d\n",idade);
    for(i = 0; i < TAM;i++)
        printf("Nota %d: %.2f\n",i+1,notas[i]);
    printf("Media das 3 notas: %.2f",media);

    
}
