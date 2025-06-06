#ifndef GAME_H
#define GAME_H

#include "mapa.h"
#include "heroi.h"

/* STRUCTS */

typedef struct
{
  Mapa* mapa;
  Heroi* heroi;
  int end;
} Game;

/* END STRUCTS */

/* FUNCTIONS */

Game* novoGame(char* nome_heroi);

/* END FUNCTIONS */

#endif