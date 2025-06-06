#ifndef HEROI_H
#define HEROI_H

#include "arma_magica.h"
#include "pocao_de_cura.h"

typedef struct
{
  ArmaMagica* armas[4];
  PocaoDeCura* pocoes[100];
  int pocao_atual;
  int hp;
  int x, y;
  char* nome;
} Heroi;

Heroi* novoHeroi(char* nome);

#endif