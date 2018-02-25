all:app
CFLAGS=-W -g
CC=g++
OBJ=main.o

app:$(OBJ)
	$(CC) -o app $(OBJ)

.PHONY:clean

clean:
	-rm -f $(OBJ) app
