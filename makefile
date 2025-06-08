CC = gcc
CFLAGS = -Wall -Wextra -g

# Lista de arquivos .c
SRC = main.c arma_magica.c bau.c bomba.c game.c heroi.c mapa.c menu.c pocao_de_cura.c tests.c utils.c tranca.c

# Gera os .o correspondentes
OBJ = $(SRC:.c=.o)

# Nome do executável
EXEC = jogo

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regra para limpar os arquivos temporários
clean:
	rm -f $(OBJ) $(EXEC)

# Recompila do zero
rebuild: clean all