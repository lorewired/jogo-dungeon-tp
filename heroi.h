#ifndef HEROI_H
#define HEROI_H

#include "arma_magica.h"
#include "pocao_de_cura.h"

typedef struct
{
  char* nome;
  ArmaMagica* armas[4];
  PocaoDeCura* pocoes[100];
  int hp, pocao_atual;
} Heroi;

Heroi* novoHeroi(char* nome);

#endif