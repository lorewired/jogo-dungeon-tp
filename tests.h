#ifndef TESTS_H
#define TESTS_H

#include "utils.h"
#include "game.h"
#include "pocao_de_cura.h"
#include "bau.h"

PocaoDeCura* testPocao();

Bau* testBau(TipoItem tipo, void* item);

void ver_baus_sorteados(Game* game);

void testarCelulas(Game* game);

#endif