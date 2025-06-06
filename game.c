#include "game.h"

/* FUNCTIONS IMPL */

Game* novoGame(char* nome_heroi)
{
  Game* game = (Game *) malloc(sizeof(Game));
  game->mapa = novoMapa(20, 20);
  game->heroi = novoHeroi(nome_heroi);
  game->end = 0;
  return game;
}

/* END FUNCTIONS IMPL */