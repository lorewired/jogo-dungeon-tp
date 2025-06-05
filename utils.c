#include "utils.h"

/* FUNCTIONS IMPL */

int random_in_range(int min_v, int max_v)
{
  return rand() % (max_v - min_v + 1) + min_v;
}

/* END FUNCTIONS IMPL */