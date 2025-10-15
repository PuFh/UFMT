# Biblioteca PyGame
import pygame
import random
from pygame.locals import *

# Classe Player com imagem personalizada
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super(Player, self).__init__()
        # Carrega a imagem do Nyan Cat
        self.surf = pygame.image.load("nyan_cat.png").convert_alpha()
        self.rect = self.surf.get_rect(center=(100, 300))  # posição inicial

    def update(self, pressed_keys):
        if pressed_keys[K_UP]:
            self.rect.move_ip(0, -5)
        if pressed_keys[K_DOWN]:
            self.rect.move_ip(0, 5)
        if pressed_keys[K_LEFT]:
            self.rect.move_ip(-5, 0)
        if pressed_keys[K_RIGHT]:
            self.rect.move_ip(5, 0)

        # Mantém o player dentro da tela
        if self.rect.left < 0:
            self.rect.left = 0
        elif self.rect.right > 800:
            self.rect.right = 800
        if self.rect.top <= 0:
            self.rect.top = 0
        elif self.rect.bottom >= 600:
            self.rect.bottom = 600


# Classe Enemy (ainda com retângulos, pode trocar depois por imagem também)
class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super(Enemy, self).__init__()
        self.surf = pygame.Surface((20, 10))
        self.surf.fill((255, 255, 255))
        self.rect = self.surf.get_rect(center=(random.randint(820, 900), random.randint(0, 600)))
        self.speed = random.uniform(1, 15)

    def update(self):
        self.rect.move_ip(-self.speed, 0)
        if self.rect.right < 0:
            self.kill()


# Inicialização
pygame.init()
screen = pygame.display.set_mode((800, 600))

# Criar jogador com imagem
player = Player()

# Grupos de sprites
enemies = pygame.sprite.Group()
all_sprites = pygame.sprite.Group()
all_sprites.add(player)

# Timer para spawn de inimigos
ADDENEMY = pygame.USEREVENT + 1
pygame.time.set_timer(ADDENEMY, 250)

running = True
while running:
    for event in pygame.event.get():
        if event.type == KEYDOWN and event.key == K_ESCAPE:
            running = False
        elif event.type == QUIT:
            running = False
        elif event.type == ADDENEMY:
            new_enemy = Enemy()
            enemies.add(new_enemy)
            all_sprites.add(new_enemy)

    pressed_keys = pygame.key.get_pressed()
    player.update(pressed_keys)
    enemies.update()

    screen.fill((0, 0, 20))  # fundo azul escuro
    for entity in all_sprites:
        screen.blit(entity.surf, entity.rect)

    if pygame.sprite.spritecollideany(player, enemies):
        player.kill()
        running = False

    pygame.display.flip()
