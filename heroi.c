#include "heroi.h"

Heroi*
novoHeroi(char* nome)
{
  Heroi* heroi = (Heroi *) malloc(sizeof(Heroi));

  heroi->armas = (ArmaMagica **) malloc(sizeof(ArmaMagica *) * 4);
  for (int i = 0; i < 4; i++)
    heroi->armas[i] = NULL;

  heroi->pocoes = (PocaoDeCura **) malloc(sizeof(PocaoDeCura *) * 100);
  for (int i = 0; i < 100; i++)
    heroi->pocoes[i] = NULL;

  heroi->total_armas = heroi->total_pocoes = 0;
  heroi->idx_arma = 0;

  heroi->nome = nome;
  heroi->rep = '#';

  heroi->hp = 100;

  return heroi;
}