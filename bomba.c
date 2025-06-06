#include "bomba.h"

Bomba*
novaBomba()
{
  Bomba* bomba = (Bomba *) malloc(sizeof(Bomba));
  bomba->dano = random_in_range(1, 4);
  return bomba;
}