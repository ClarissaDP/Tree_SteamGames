#definição de variáveis
OBJ=main.o AVL.o DTQ.o steamGames.o

all: inicial steamGames clean

inicial: 
	@echo "Iniciando"

steamGames:$(OBJ)
	@gcc -o steamGames $(OBJ)
main.o: steamGames.h main.c
	@gcc -c main.c 
steamGames.o: steamGames.h steamGames.c 
	@gcc -c steamGames.c 
AVL.o: steamGames.h AVL.c 
	@gcc -c AVL.c 
DTQ.o: steamGames.h DTQ.c 
	@gcc -c DTQ.c 

#remove arquivos objetos
clean:
	@echo "Finalizando"
	@rm -rf *.o
