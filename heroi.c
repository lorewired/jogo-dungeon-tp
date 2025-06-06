#include "heroi.h"

Heroi*
novoHeroi(char* nome)
{
  Heroi* heroi = (Heroi *) malloc(sizeof(Heroi));
  heroi->nome = nome;
  heroi->hp = 100;
  heroi->pocao_atual = 0;
  return heroi;
}