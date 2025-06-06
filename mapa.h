#ifndef MAPA_H
#define MAPA_H

#include "utils.h"
#include "tranca.h"
#include "bau.h"

/* STRUCTS */

typedef enum
{
  ROCHA,
  BAU,
  PAREDE,
  TRANCA_MAGICA,
  TRANCA_MAGICA_QUEBRADA,
  TESOURO,
  NADA
} TipoCelula;

typedef struct
{
  void* data;
  int solido;
  char carac;
  TipoCelula tipo;
} Celula;

typedef struct
{
  Celula*** matriz;
  Bau** baus;
  int max_x, max_y;
  int qntd_baus;
  int heroi_x_inicial, heroi_y_inicial;
} Mapa;

/* END STRUCTS */

/* FUNCTIONS */

Mapa*
novoMapa(int max_x, int max_y);

Celula*
novaCelula(TipoCelula tipo, void* data);

void
ler_mapa(Mapa* mapa, char* arquivo, int N, int M);

void
posicionar_armas(Mapa* game);

/* END FUNCTIONS */

#endif