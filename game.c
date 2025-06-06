#include "game.h"

/* FUNCTIONS IMPL */

Game* novoGame(char* nome_heroi)
{
  Game* game = (Game *) malloc(sizeof(Game));
  game->heroi = novoHeroi(nome_heroi);
  game->mapa = NULL;
  game->end = 0;
  return game;
}

/* END FUNCTIONS IMPL */