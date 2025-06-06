#include "tests.h"

PocaoDeCura*
testPocao()
{
  return novaPocao();
}

Bau*
testBau(TipoItem tipo, void* item)
{
  return novoBau(tipo, item);
}

void
testarCelulas(Game* game)
{
  int x, y;
  printf("X: ");
  scanf("%d", &x);
  printf("Y: ");
  scanf("%d", &y);

  Celula* cel = game->mapa->matriz[x][y];
  
  printf("\nCELULA %d %d\n");
  printf("Tipo: ");

  if (cel->tipo == BAU) printf("BAU\n");
  if (cel->tipo == ROCHA) printf("ROCHA\n");
  if (cel->tipo == PAREDE) printf("PAREDE\n");
  if (cel->tipo == TRANCA_MAGICA) printf("TRANCA_MAGICA\n");
  if (cel->tipo == TRANCA_MAGICA_QUEBRADA) printf("TRANCA_MAGICA_QUEBRADA\n");
  if (cel->tipo == TESOURO) printf("TESOURO\n");
  if (cel->tipo == NADA) printf("NADA\n");
  if (x == game->heroi->x && y == game->heroi->y) printf("HEROI\n");
  
  printf("\n");
}