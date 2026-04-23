#include <iostream>

int main(){
    int ano, trimestre;
    ano = 2;
    trimestre = 3;
    double despesas[ano][trimestre];

    //atribuindo despesas
    for(int i = 0; i < ano; i++){
        for(int j = 0; j < trimestre; j++){
            std::printf("Depesas do %d trimestre no ano %d: ",j+1,i+1);
            std::cin >> despesas[i][j];
        }
    }
   //impressao
   std::printf("ANO/TRIMESTRE");
   for(int i = 0; i < trimestre; i++){
        std::printf("   %d   ",i+1);
   }
   std::printf("\n");

   for(int i = 0; i < ano;i++){
       std::printf("      ");
       std::printf("%d ",i+1);
       std::printf("  | ");
        for(int j = 0; j < trimestre; j++){
            std::printf("%.2f ",despesas[i][j]);
            std::printf("|   ");
            if(j == trimestre - 1){
                std::printf("\n");
            }       
        }
   }

    return 1;
}