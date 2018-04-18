all:multiThread
CFLAGS=-W -g -std=c++11
CC=g++
OBJ=main.o threadpool.o

multiThread:$(OBJ)
	$(CC) $(CFLAGS) -o multiThread $(OBJ)

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

threadpool.o:threadpool.cpp
	$(CC) $(CFLAGS) -c threadpool.cpp

.PHONY:clean

clean:
	-rm -f $(OBJ) multiThread
