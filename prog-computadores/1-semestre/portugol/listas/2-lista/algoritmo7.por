programa {
  inclua biblioteca Matematica --> mat
  funcao inicio() {
    inteiro termos, contador, denominador, sinal
    real pi,soma
    
    soma=0
    pi=0
    denominador = 1
    contador=0
    sinal =1
    escreva("Digite o número de termos: ")
    leia(termos)

    se (termos > 0 e termos <=20){
      enquanto(contador < termos){
        soma +=sinal*(1/mat.potencia(denominador, 3))
        escreva(soma,"\n")
       
        denominador = denominador+2
        sinal = sinal*-1
        contador++
      }
    }senao{
      escreva("Digite um número entre 1 e 20 para os termos.")
    }
    pi = mat.raiz(soma*32,3)

    escreva("\nO valor aproximado, utilizando "+termos+" termos, foi:"+pi)
  }
}
