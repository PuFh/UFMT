#copiar o arquivo milsa para este arqivo para trabalharmos em cima dele
milsa <- read.table("milsa.txt",head = T)#Comando head define q a 1 liha é um cabechalo
milsa
head(milsa)

milsa$salario 
#faço com que o valor 1 = solteiro desta coluna, e o valor 2 = casado
milsa $civil <- factor(milsa$civil, label = c("solteiro", "casado"), levels = 1:2)
#mesma coisa
milsa$instrucao <- factor(milsa$instrucao, label = c("1 grau","2 grau","superiro"),lev=1:3, ord = T)
#mesma coisa
milsa$regiao <- factor(milsa$regiao, labels = c("Captial","Interior","Outro"), lev = c(2,1,3))
 
is.factor(milsa$regiao)
