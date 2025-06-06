#include "menu.h"

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
  sleep(1);
  clear_tm();
}

Game*
boasVindas()
{
  load_splash_art();

  printf("Bem-vindo Jogador!\n\nDigite o nome do seu personagem: ");
  char nome[100];

  fgets(nome, 100, stdin);

  Game* game = novoGame(nome);
  return game;
}

void
iniciarJogo()
{;
  Game* game = boasVindas();

  while (!game->end)
  {
    
  }
}