#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "mapa.h"

typedef struct
{
  Menu menu;
  Mapa* mapa;
} Game;

Game
newGame()
{
  Game game;
  game.menu = novoMenu();
  game.mapa = novoMapa();
}

#endif