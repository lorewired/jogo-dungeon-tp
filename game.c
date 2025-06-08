#include "game.h"

/* FUNCTIONS IMPL */

Game* novoGame(char* nome_heroi)
{
  Game* game = (Game *) malloc(sizeof(Game));
  game->heroi = novoHeroi(nome_heroi);
  game->mapa = NULL;
  game->end = 0;
  return game;
}

int
valid_coords(Mapa* mapa, int x, int y)
{
  return
    x >= 0 &&
    y >= 0 &&
    x < mapa->max_x &&
    y < mapa->max_y;
}

void
mover_heroi(Game* game, int x, int y)
{
  if (
    x < 0 ||
    y < 0 ||
    x == game->mapa->max_x ||
    y == game->mapa->max_y ||
    game->mapa->matriz[x][y]->solido
  ) return;

  game->heroi->x = x;
  game->heroi->y = y;
}

void
abrir_bau(Game* game)
{
  Heroi* heroi = game->heroi;

  int x = heroi->x;
  int y = heroi->y;
  
  if (game->mapa->matriz[x][y]->tipo != BAU) return;

  Bau* bau = (Bau *) game->mapa->matriz[x][y]->data;

  if (bau->aberto) return;
  
  ((Celula *) game->mapa->matriz[x][y])->rep = 'b';  
  bau->aberto = 1;
   
  switch (bau->tipo_item)
  {
    case BAU_ARMA_MAGICA:
      ArmaMagica* arma = (ArmaMagica *) bau->item;

      heroi->armas[heroi->idx_arma] = arma;
      heroi->total_armas++;
      heroi->idx_arma++;
      heroi->idx_arma %= 4;
      
      system("aplay arma.wav > /dev/null 2>&1");
      break;
    case BAU_POCAO_DE_VIDA:
      PocaoDeCura* pocao = (PocaoDeCura *) bau->item;

      if (heroi->total_pocoes < 100)
        heroi->pocoes[heroi->total_pocoes++] = pocao;
      
      break;
    case BAU_BOMBA:
      Bomba* bomba = (Bomba *) bau->item;
      
      heroi->hp -= bomba->dano;

      system("aplay hit.wav > /dev/null 2>&1");
      break;
  }
}

void
trocar_de_arma(Heroi* heroi)
{
  heroi->idx_arma = (heroi->idx_arma + 1) % 4;
}

int
atacar(Game* game)
{
  int ci[] = {-1, 0, 1, 0};
  int cj[] = {0, 1, 0, -1};

  Heroi* heroi = game->heroi;

  for (int i = 0; i < 4; i++)
  {
    int x = heroi->x + ci[i];
    int y = heroi->y + cj[i];

    if (valid_coords(game->mapa, x, y))
    {
      Celula* cel = game->mapa->matriz[x][y];

      switch (cel->tipo)
      {
        case ROCHA:
          cel->rep = ' ';
          cel->solido = 0;
          break;
        case TRANCA_MAGICA:
          Tranca* tranca = (Tranca *) cel->data;

          if (heroi->armas[heroi->idx_arma]->elemento != tranca->fraqueza)
            return 0;

          tranca->quebrada = 1;

          cel->solido = 0;
          cel->rep = tolower(cel->tipo);
          cel->tipo = TRANCA_MAGICA_QUEBRADA;
          break;
      }
    }
  }

  system("aplay attack.wav > /dev/null 2>&1");
  return 1;
}


/* END FUNCTIONS IMPL */