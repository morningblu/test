CFLGS = -g -W
OBJS = main.o single_link.o
CC = gcc

Link : $(OBJS)
	$(CC) ${CFLGS} -o $@ ${OBJS}

main.o: main.c
	$(CC) ${CFLGS} -c main.c

single_link.o : single_link.c single_link.h
	$(CC) ${CFLGS} -c single_link.c

.PHONY:clean

clean:
	-rm -f ${OBJS} Link
