#include "tranca.h"

Tranca*
novaTranca(Elemento fraqueza, char* nome)
{
  Tranca* tranca = (Tranca *) malloc(sizeof(Tranca));
  
  tranca->fraqueza = fraqueza;
  tranca->nome = nome;
  tranca->quebrada = 0;

  return tranca;
}