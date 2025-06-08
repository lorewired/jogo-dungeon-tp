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
ver_baus_sorteados(Game* game)
{
  for (int i = 0; i < game->mapa->qntd_baus; i++)
  {
    Bau* bau = game->mapa->baus[i];
    if (bau->tipo_item == BAU_ARMA_MAGICA)
      printf("arma magica\n");
    else if (bau->tipo_item == BAU_BOMBA)
      printf("bomba\n");
    else if (bau->tipo_item == BAU_POCAO_DE_VIDA)
      printf("pocao de vida\n");
    else
      printf("erro ao armazenar item\n"); // deu pra armazenar td :D
  }
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
  
  printf("\nCELULA %d %d\n", x, y);
  printf("Tipo: ");

  switch (cel->tipo)
  {
    case BAU:
      printf("BAU\n");
      break;
    case ROCHA:
      printf("ROCHA\n");
      break;
    case PAREDE:
      printf("PAREDE\n");
      break;
    case TRANCA_MAGICA:
      printf("TRANCA_MAGICA\n");
      break;
    case TRANCA_MAGICA_QUEBRADA:
      printf("TRANCA_MAGICA_QUEBRADA\n");
      break;
    case TESOURO:
      printf("TESOURO\n");
      break;
    case NADA:
      printf("NADA\n");
      break;
    default:
      printf("TIPO DESCONHECIDO\n");
  }

  printf("\n");
}