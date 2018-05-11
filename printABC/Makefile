all:run
CC=g++ -std=c++11
FLAG=-g -W
LIBS=-pthread

run:main.o
	$(CC) $(FLAG) -o run main.cpp $(LIBS)

main.o:main.cpp
	$(CC) $(FLAG) -c main.cpp $(LIBS)

.PHONY:clean

clean:
	-rm -f *.o run
