#include "pocao_de_cura.h"

/* FUNCTIONS IMPL */

PocaoDeCura*
novaPocao()
{
  PocaoDeCura* pocao = (PocaoDeCura *) malloc(sizeof(PocaoDeCura));
  pocao->pontos = random_in_range(1, 3);
  return pocao;
}

/* END FUNCTIONS IMPL */