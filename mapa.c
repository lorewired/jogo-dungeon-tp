#include "mapa.h"

/* FUNCTIONS IMPL */

Mapa*
novoMapa(int max_x, int max_y)
{
  Mapa* mapa = (Mapa *) malloc(sizeof(Mapa));
  mapa->matriz = (Celula ***) malloc(sizeof(Celula **) * max_x);

  for (int i = 0; i < max_y; i++)
    mapa->matriz[i] = (Celula **) malloc(sizeof(Celula *) * max_y);

  mapa->baus = (Bau **) malloc(sizeof(Bau *));

  return mapa;
}

Celula*
novaCelula(TipoCelula tipo, void* data)
{
  Celula* cel = (Celula *) malloc(sizeof(Celula));
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

  return cel;
}

void
ler_mapa(Mapa* mapa, char* arquivo, int max_x, int max_y)
{
  FILE* f = fopen(arquivo, "r");

  for (int i = 0; i < max_x; i++) {
    for (int j = 0; j < max_y;) {
      char c;
      if (fscanf(f, "%c", &c) != 1) break;

      if (c == '\n' || c == '\r') continue;
      
      Celula* cel = (Celula *) malloc(sizeof(Celula));
      cel->carac = c;

      switch (cel->carac)
      {
        case 'W':
          cel->tipo = TRANCA_MAGICA;
          cel->data = novaTranca(AGUA, "Tranca Magica de Agua");
          cel->solido = 1;
          break;
        case 'E':
          cel->tipo = TRANCA_MAGICA;
          cel->data = novaTranca(TERRA, "Tranca Magica de Terra");
          cel->solido = 1;
          break;
        case 'F':
          cel->tipo = TRANCA_MAGICA;
          cel->data = novaTranca(FOGO, "Tranca Magica de Fogo");
          cel->solido = 1;
          break;
        case 'A':
          cel->tipo = TRANCA_MAGICA;
          cel->data = novaTranca(AR, "Tranca Magica de Ar");
          cel->solido = 1;
          break;
        case 'B':
          cel->tipo = BAU;
          cel->solido = 0;

          int tipo = random_in_range(0, 1);

          if (tipo)
            cel->data = novoBau(BAU_POCAO_DE_VIDA, novaPocao());
          else
            cel->data = novoBau(BAU_BOMBA, novaBomba());

          int next_idx = mapa->qntd_baus++;
          mapa->baus = realloc(mapa->baus, sizeof(Bau *) * mapa->qntd_baus);
          mapa->baus[next_idx] = (Bau *) cel->data;
          
          break;
        case '@':
          cel->tipo = TESOURO;
          cel->data = NULL;
          cel->solido = 1;
          break;
        case 'R':
          cel->tipo = ROCHA;
          cel->data = NULL;
          cel->solido = 1;
          break;
        case '*':
          cel->tipo = PAREDE;
          cel->data = NULL;
          cel->solido = 1;
          break;
        case '#':
          mapa->heroi_x_inicial = i;
          mapa->heroi_y_inicial = j;
        default:
          cel->tipo = NADA;
          cel->data = NULL;
          cel->solido = 0;
      }

      mapa->matriz[i][j] = cel;
      j++;
    }
  }

  fclose(f);
}

void
posicionar_armas(Mapa* mapa)
{
  int selected[mapa->qntd_baus];
  memset(selected, 0, sizeof(selected));

  Elemento elementos[4] = {
    AGUA,
    AR,
    FOGO,
    TERRA
  };

  char* nomes[4] = {
    "Arma de Agua",
    "Arma de Ar",
    "Arma de Fogo",
    "Arma de Terra"
  };

  int sel = 0;

  for (int i = 0; i < 4; i++)
  {
    int idx;

    do { idx = random_in_range(0, mapa->qntd_baus - 1); }
    while (selected[idx]);

    selected[idx] = 1;

    mapa->baus[idx]->tipo_item =
      BAU_ARMA_MAGICA;
      
    mapa->baus[idx]->item =
      novaArmaMagica(elementos[sel], nomes[sel]);
      
    sel++;
  }
}

/* END FUNCTIONS IMPL */