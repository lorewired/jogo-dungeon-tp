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

typedef enum
{
  SEL_AGUA = 0,
  SEL_TERRA = 1,
  SEL_FOGO = 2,
  SEL_AR = 3
} Elementos;

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