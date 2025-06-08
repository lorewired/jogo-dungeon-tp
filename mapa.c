#include "mapa.h"

/* FUNCTIONS IMPL */

Mapa*
novoMapa(int max_x, int max_y)
{
  Mapa* mapa = (Mapa *) malloc(sizeof(Mapa));
  mapa->matriz = (Celula ***) malloc(sizeof(Celula **) * max_x);

  for (int i = 0; i < max_x; i++)
    mapa->matriz[i] = (Celula **) malloc(sizeof(Celula *) * max_y);

    mapa->max_x = max_x;
    mapa->max_y = max_y;

    mapa->baus = NULL;
    mapa->qntd_baus = 0;

  return mapa;
}

Celula*
novaCelula(TipoCelula tipo, void* data, char rep)
{
  Celula* cel = (Celula *) malloc(sizeof(Celula));
  cel->tipo = tipo;
  cel->rep = rep;
  cel->solido =
    tipo == PAREDE ||
    tipo == ROCHA ||
    tipo == TRANCA_MAGICA;

  cel->data = data;

  return cel;
}

void
ler_mapa(Mapa* mapa, char* arquivo, int max_x, int max_y)
{
  FILE* f = fopen(arquivo, "r");
  
  int i = 0, j = 0;
  char c;
  
  while (fread(&c, 1, 1, f))
  {
    if (c == '\n' || c == '\r') continue;

    Celula* cel;

    switch (c)
    {
      case 'W':
        cel = novaCelula(TRANCA_MAGICA, novaTranca(AGUA, "Tranca Magica de Agua"), 'W');
        break;
      case 'E':
        cel = novaCelula(TRANCA_MAGICA, novaTranca(TERRA, "Tranca Magica de Terra"), 'E');
        break;
      case 'F':
        cel = novaCelula(TRANCA_MAGICA, novaTranca(FOGO, "Tranca Magica de Fogo"), 'F');
        break;
      case 'A':
        cel = novaCelula(TRANCA_MAGICA, novaTranca(AR, "Tranca Magica de Ar"), 'A');
        break;
      case 'B':
        int tipo = random_in_range(0, 1);
  
        if (tipo)
          cel = novaCelula(BAU, novoBau(BAU_POCAO_DE_VIDA, novaPocao()), 'B');
        else
          cel = novaCelula(BAU, novoBau(BAU_BOMBA, novaBomba()), 'B');
  
        mapa->baus = realloc(mapa->baus, sizeof(Bau *) * (mapa->qntd_baus + 1));
        mapa->baus[mapa->qntd_baus] = (Bau *) cel->data;
        mapa->qntd_baus++;
        
        break;
      case '@':
        cel = novaCelula(TESOURO, NULL, '@');
        break;
      case 'R':
        cel = novaCelula(ROCHA, NULL, 'R');
        break;
      case '*':
        cel = novaCelula(PAREDE, NULL, '*');
        break;
      case '#':
        mapa->heroi_x_inicial = i;
        mapa->heroi_y_inicial = j;
      default:
        cel = novaCelula(NADA, NULL, ' ');
        break;
    }
  
    mapa->matriz[i][j] = cel;

    j++;
    if (j == max_y)
    {
      i++;
      j = 0;
    }

    if (i == max_x) break;
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