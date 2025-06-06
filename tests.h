#ifndef TESTS_H
#define TESTS_H

#include "utils.h"
#include "game.h"
#include "pocao_de_cura.h"
#include "bau.h"

PocaoDeCura* testPocao();

Bau* testBau(TipoItem tipo, void* item);

void testarCelulas(Game* game);

#endif