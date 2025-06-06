#include "bau.h"

/* FUNCTIONS IMPL */

Bau*
novoBau(TipoItem tipo_item, void* item)
{
  Bau* bau = (Bau *) malloc(sizeof(Bau));
  bau->tipo_item = tipo_item;
  
  switch (tipo_item)
  {
    case BAU_ARMA_MAGICA: bau->item = (ArmaMagica *) item; break;
    case BAU_POCAO_DE_VIDA: bau->item = (PocaoDeCura *) item; break;
    case BAU_BOMBA: bau->item = (Bomba *) item;
  }

  return bau;
}

/* END FUNCTIONS IMPL */