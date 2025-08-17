programa {
  funcao inicio() {
    real n,i,soma
    i=1
    soma=0

    escreva("Digite o valor da sequência: \n")
    leia(n)

    
    enquanto(i <= n){
      soma =soma+(1/i)
      i +=1
      
    }
    escreva(soma)
  }
}

