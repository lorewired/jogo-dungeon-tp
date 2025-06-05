#include "tests.h"

PocaoDeCura*
testPocao()
{
  return novaPocao();
}

Bau*
testBau(TipoItem tipo, void* item)
{
  return novoBau(tipo, item);
}