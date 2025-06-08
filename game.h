#ifndef GAME_H
#define GAME_H

#include "utils.h"
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

int valid_coords(Mapa* mapa, int x, int y);

void mover_heroi(Game* game, int x, int y);

void abrir_bau(Game* game);

void trocar_de_arma(Heroi* heroi);

int atacar(Game * game);

/* END FUNCTIONS */

#endif