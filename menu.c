#include "menu.h"
#include "tests.h"

void
clear_tm()
{
  printf("\033[H\033[J");
  fflush(stdout);
}

void
load_splash_art()
{
  clear_tm();
  FILE* f = fopen("knight.txt", "r");
  char c;
  printf("\n\t\t\t\tLOADING...\n\n");
  while (!feof(f)) {
    c = fgetc(f);
    printf("%c", c);
  }
  // sleep(5);
  sleep(2);
  clear_tm();
}

Game*
boasVindas()
{
  load_splash_art();
  
  printf("Bem-vindo Jogador!\n\n[10 char no maximo] Digite o nome do seu personagem: ");
  char nome[100];
  fgets(nome, 100, stdin);
  
  Game* game = novoGame(nome);

  printf("Mapas disponiveis: [1] Mapa A , [2] Mapa B\nSelecionar: ");
  int escolha_mapa;
  scanf("%d", &escolha_mapa);
  
  if (escolha_mapa == 1)
  {
    game->mapa = novoMapa(10, 29);
    ler_mapa(game->mapa, "jogo_exploracao-mapa_a.txt", 10, 29);
  }
  else
  {
    game->mapa = novoMapa(16, 41);
    ler_mapa(game->mapa, "jogo_exploracao-mapa_b.txt", 16, 41);
  }

  game->heroi->x = game->mapa->heroi_x_inicial;
  game->heroi->y = game->mapa->heroi_y_inicial;

  posicionar_armas(game->mapa);

  return game;
}

void
iniciarJogo()
{
  Game* game = boasVindas();

  while (!game->end || game->heroi->hp > 0)
  {
    testarCelulas(game);
  }
}