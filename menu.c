#include "menu.h"

void
clear_tm()
{
  printf("\033[H\033[J");
  fflush(stdout);
}

void
load_splash_art()
{
  clear_tm();
  FILE* f = fopen("knight.txt", "r");
  char c;
  printf("\n\t\t\t\tLOADING...\n\n");
  while (!feof(f)) {
    c = fgetc(f);
    printf("%c", c);
  }
  // sleep(5);
  sleep(2);
  clear_tm();
}

Game*
boasVindas()
{
  load_splash_art();
  
  printf("Bem-vindo Jogador!\n\n[10 char no maximo] Digite o nome do seu personagem: ");
  char nome[100];
  fgets(nome, 100, stdin);
  
  Game* game = novoGame(nome);

  printf("Mapas disponiveis: [1] Mapa A , [2] Mapa B\nSelecionar: ");

  char linha[10];
  fgets(linha, sizeof(linha), stdin); // problema com buffer, pedi ajuda pro grok pq n estava conseguindo resolver :(

  int escolha_mapa;
  sscanf(linha, "%d", &escolha_mapa); 
  
  if (escolha_mapa == 1)
  {
    game->mapa = novoMapa(10, 29);
    ler_mapa(game->mapa, "jogo_exploracao-mapa_a.txt", 10, 29);
  }
  else
  {
    game->mapa = novoMapa(16, 41);
    ler_mapa(game->mapa, "jogo_exploracao-mapa_b.txt", 16, 41);
  }

  game->heroi->x = game->mapa->heroi_x_inicial;
  game->heroi->y = game->mapa->heroi_y_inicial;

  posicionar_armas(game->mapa);

  return game;
}

void
ler_comando(Game* game)
{
  printf("Comando: ");

  char linha[10];
  fgets(linha, 10, stdin);
  char inp = linha[0];

  if (isdigit(inp))
  {
    // beber pocao
    return;
  }

  switch (inp)
  {
    case 'W':
      mover_heroi(game, game->heroi->x - 1, game->heroi->y);
      break;
    case 'A':
      mover_heroi(game, game->heroi->x, game->heroi->y - 1);
      break;
    case 'S':
      mover_heroi(game, game->heroi->x + 1, game->heroi->y);
      break;
    case 'D':
      mover_heroi(game, game->heroi->x, game->heroi->y + 1);
      break;
    case 'O':
      abrir_bau(game);
      break;  
    case 'P':
      atacar(game);
      break;
    case 'L':
      trocar_de_arma(game->heroi);
  }
}

void
comando_invalido()
{
  printf("\nComando Invalido.");
  sleep(1);
}

void
exibir_bolsa_de_armas(Heroi* heroi)
{
  if (!heroi->total_armas) {
    printf("Vazia\n");
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    if (heroi->armas[i] != NULL)
    {
      ArmaMagica* arma = (ArmaMagica *) heroi->armas[i];
      printf("%s", arma->nome);
      if (i + 1 < 4 && heroi->armas[i + 1] != NULL)
        printf(" | ");
    }
  }

  printf("\n");
}

void
exibir_mapa(Game* game)
{
  for (int i = 0; i < game->mapa->max_x; i++)
  {
    for (int j = 0; j < game->mapa->max_y; j++) {
      if (i == game->heroi->x && j == game->heroi->y)
        printf("#");
      else
        printf("%c", game->mapa->matriz[i][j]->rep);
    }
    printf("\n");
  }
}

void
exibir_interface(Game* game)
{
  printf("\n");
  printf("HP: %d\n", game->heroi->hp);
  printf("Bolsa de Armas: ");
  exibir_bolsa_de_armas(game->heroi);
  printf("Pocoes de Cura: %d\n", game->heroi->total_pocoes);
}

void
iniciarJogo()
{
  Game* game = boasVindas();

  while (!game->end || game->heroi->hp > 0)
  {
    clear_tm();
    exibir_mapa(game);
    exibir_interface(game);
    ler_comando(game);
  }
}