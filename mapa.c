#include "mapa.h"

/* FUNCTIONS IMPL */

Mapa*
novoMapa(int max_x, int max_y)
{
  Mapa mapa;
  mapa.matriz = (Celula ***) malloc(sizeof(Celula **) * max_x);

  for (size_t i = 0; i < max_y; i++)
    mapa.matriz[i] = (Celula **) malloc(sizeof(Celula *) * max_y);
  
  return &mapa;
}

Celula*
novaCelula(int x, int y, TipoCelula tipo, void* data)
{
  Celula* cel = (Celula *) malloc(sizeof(Celula));
  cel->x = x;
  cel->y = y;
  cel->tipo = tipo;
  cel->solido =
    tipo == BAU ||
    tipo == TESOURO ||
    tipo == TRANCA_MAGICA_QUEBRADA;
    
  switch (tipo)
  {
    case BAU: cel->data = (Bau *) data; break;
    case TRANCA_MAGICA: cel->data = (Tranca *) data; break;
    default: cel->data = NULL;
  }
}

/* END FUNCTIONS IMPL */