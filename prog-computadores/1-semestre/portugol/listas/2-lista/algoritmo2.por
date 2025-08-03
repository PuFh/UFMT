programa {
  funcao inicio() {
    
    inteiro total, nota, contador, media
    nota = 0
    total = 0
    contador=0
    enquanto (nota >= 0 ){
      escreva("Digite a nota: ")
      leia(nota)

      total = total+nota
      contador++
    }
    media = 0
    media = total/contador
    escreva("A média de suas notas é "+media)
    
  }
}
