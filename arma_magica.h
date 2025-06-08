#ifndef ARMA_MAGICA_H
#define ARMA_MAGICA_H

#include "utils.h"

/* STRUCTS */

typedef enum
{
  AGUA,
  TERRA,
  FOGO,
  AR
} Elemento;

typedef struct
{
  char* nome;
  Elemento elemento;
} ArmaMagica;

/* END STRUCTS */

/* FUNCTIONS */

ArmaMagica* novaArmaMagica(Elemento elemento, char* nome);

/* END FUNCTIONS */

#endif