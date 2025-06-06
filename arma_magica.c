#include "arma_magica.h"

/* FUNCTIONS IMPL */

ArmaMagica*
novaArmaMagica(Elemento elemento, char* nome)
{
  ArmaMagica* arma = (ArmaMagica *) malloc(sizeof(ArmaMagica));
  
  arma->nome = nome;
  arma->elemento = elemento;
  
  return arma;
}

/* END FUNCTIONS IMPL */