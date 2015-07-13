############################################
# Adriana Devera y Maria de Lourdes Garcia #
# Tarea					   #
############################################

CC = gcc
HEAD = funciones.h lista.h
OBJ = funciones.o lista.o filetree.o
OPT= -std=gnu99
PROG = fileTree

$(PROG): $(OBJ)
	$(CC) $(OBJ) -o $(PROG) $(OPT)

filetree.o: funciones.o filetree.c $(HEAD)
	$(CC) -c filetree.c $(OPT)

funciones.o: lista.o funciones.c $(HEAD)
	$(CC) -c funciones.c $(OPT)

lista.o: lista.c 
	$(CC) -c lista.c $(OPT)

clean:
	rm $(OBJ) $(PROG)

