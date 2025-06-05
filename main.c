#include "utils.h"
#include "tests.h"
#include "pocao_de_cura.h"

int main()
{
  srand(time(NULL)); 
  PocaoDeCura* pocao = novaPocao();
  Bau* bau = novoBau(BAU_POCAO_DE_VIDA, pocao);
  
  return 0;
}