#ifndef TRANCA_H
#define TRANCA_H

#include "arma_magica.h"

/* STRUCTS */

typedef struct
{
  char* nome;
  Elemento fraqueza;
} Tranca;

#endif

/* END STRUCTS */

/* FUNCTIONS */

Tranca* novaTranca(Elemento fraqueza, char* nome);

/* END FUNCTIONS */