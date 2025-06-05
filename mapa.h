#ifndef MAPA_H
#define MAPA_H

#include "utils.h"
#include "bau.h"
#include "tranca.h"

/* STRUCTS */

typedef enum
{
  ROCHA,
  BAU,
  PAREDE,
  TRANCA_MAGICA,
  TRANCA_MAGICA_QUEBRADA,
  TESOURO
} TipoCelula;

typedef struct
{
  int x, y;
  void* data;
  int solido;
  TipoCelula tipo;
} Celula;

typedef struct
{
  Celula*** matriz;
  int max_x, max_y;
} Mapa;

/* END STRUCTS */

/* FUNCTIONS */

Mapa
novoMapa(int max_x, int max_y);

Celula*
novaCelula(int x, int y, TipoCelula tipo, void* data);

/* END FUNCTIONS */

#endif