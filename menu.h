#ifndef MENU_H
#define MENU_H

#include "utils.h"
#include "game.h"
#include "mapa.h"

void clear_tm();

void iniciarJogo();

Game* boasVindas();

void load_splash_art();

void ler_comando(Game* game);

void comando_invalido();

void exibir_mapa(Game* game);

#endif