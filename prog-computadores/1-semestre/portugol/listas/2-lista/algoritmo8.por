programa {
  funcao inicio() {
    inteiro termo, i, a,b,c
     
    escreva("Digite o termo da sequência de Fibonacci: ")
    leia(termo)
    a=1
    b=1
    i=0
    enquanto(i < termo){
      escreva(a," ")
      c = a+b
      a=b
      b=c
      i++
    }
  }
}
