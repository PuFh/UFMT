programa {
  funcao inicio() {
    real altura[6], max_altura, min_altura, soma, media
    inteiro pos_altura
    
    soma=0
    pos_altura=0
    
    //dando valores para o vetor altura
    enquanto (pos_altura < 6){
      escreva("Digite a altura:\n")
      leia(altura[pos_altura])
      pos_altura++
    }
    //fazendo a média de altura
    pos_altura = 0
    para(pos_altura=0; pos_altura<6;pos_altura++){
      soma = soma + altura[pos_altura]

    }
    media = soma/6
    
    //Verificando a menor altura
    min_altura = altura[0]
    max_altura = altura[0]
    para(pos_altura=0; pos_altura < 5; pos_altura++){
      se (altura[pos_altura] < min_altura){
        min_altura = altura[pos_altura]

      }
    }
    //verificando a maior altura
    para(pos_altura=0; pos_altura < 5; pos_altura++){
      se (altura[pos_altura] > max_altura){
        max_altura = altura[pos_altura]

      }
    }
    escreva("A média de alturas é de: "+media+"\n")
    escreva("a Menor altura é "+min_altura+" e a maior é "+max_altura)
  }
}
