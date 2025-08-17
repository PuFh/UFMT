programa {
  funcao inicio() {
    real montante,imposto, deducao,mon_ajustado, alicota

    escreva("Digite o seu valor monetário:\n")
    leia(montante)

    se (montante < 22000){
      escreva("Você está insento das deduções, o seu patriomônio continua "+montante)
    }
    se (montante >= 22000 e montante <= 33000){
      imposto = 7.5/100
      alicota = montante*imposto
      deducao = montante - alicota
      escreva("O seu patrimônio foi de "+montante+"R$ para "+deducao+"R$ com uma alicota de "+alicota+"R$")
    }
    se (montante > 33000 e montante <= 55000 ){
      imposto = 22.5/100
      alicota = montante*imposto
      deducao = montante - alicota
      escreva("O seu patrimônio foi de "+montante+"R$ para "+deducao+"R$ com uma alicota de "+alicota+"R$")
    }
    se (montante > 55000){
      imposto = 22.5/100
      alicota = montante*imposto
      deducao = montante - alicota
      escreva("O seu patrimônio foi de "+montante+"R$ para "+deducao+"R$ com uma alicota de "+alicota+"R$")
    }
  }
}
