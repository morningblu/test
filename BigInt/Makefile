all:app
CFLAGS=-W -g
CC=g++
OBJ=main.o BigInt.o

app:$(OBJ)
	$(CC) $(CFLAGS) -o app $(OBJ)

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

BigInt.o:BigInt.cpp
	$(CC) $(CFLAGS) -c BigInt.cpp

.PHONY:clean

clean:
	-rm -f $(OBJ) app
