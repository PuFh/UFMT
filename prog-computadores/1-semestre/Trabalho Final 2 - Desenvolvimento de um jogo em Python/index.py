import pygame

#Verificação para ver se a instalação da biblioteca foi realizada adequadamente
from pygame.locals import *
pygame.init()
#TAMANHO DA TELA
screen = pygame.display.set_mode((800,600))

running = True

#Loop Principal
while running:
    #laco que captura e verifica todos os eventos no jogo
    for event in pygame.event.get():
        # Verefica se ocorreu o evento KEYDOWN; KEYDOWN eh uma constante definida em pygame.locals
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                # Se a tecla ESC foi pressionada, modifica a flag para então
                # terminar o loop do jogo
                running = False
        # Verifica se ocorreu o evento de SAIDA (fechamento da janela)
        elif event.type == QUIT:
            running = False
            
'''--------------------Definindo uma SUPERFICIE---------------------
Uma superfície, ou bloco, é qualquer objeto do jogo. Pode se um personagem, ou uma barreira,
por exemplo. Vamos definir um simples retângulo e coloca-lo na tela do jogo:
'''
#cria uma superfície com tamanho 50px x 25px
surf = pygame.Surface((50,25))

#preenchimento com alguma cor(RGB)
surf.fill((255,255,255))
rect = surf.get_rect()

#Ploata o objeto na tela criada,
screen.blit(surf,(400,300))
pygame.display.flip() # Este comando tem a função de atualizar a posição
 #