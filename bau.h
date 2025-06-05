#ifndef BAU_H
#define BAU_H

#include "arma_magica.h"
#include "pocao_de_cura.h"
#include "bomba.h"

/* STRUCTS */

typedef enum
{
  BAU_ARMA_MAGICA,
  BAU_POCAO_DE_VIDA,
  BAU_BOMBA
} TipoItem;

typedef struct
{
  TipoItem tipo_item;
  void* item;
} Bau;

/* END STRUCTS */

/* FUNCTIONS */

Bau* novoBau(TipoItem tipo_item, void* item);

/* END FUNCTIONS */

#endif