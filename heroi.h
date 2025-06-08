#ifndef HEROI_H
#define HEROI_H

#include "arma_magica.h"
#include "pocao_de_cura.h"

/* STRUCTS */

typedef struct
{
  ArmaMagica** armas;
  PocaoDeCura** pocoes;
  int total_armas, idx_arma;
  int total_pocoes;
  int x, y;
  int hp;
  char* nome;
  char rep;
} Heroi;

/* END STRUCTS */

/* FUNCTIONS */

Heroi* novoHeroi(char* nome);

/* END FUNCTIONS */

#endif