CFLGS = -g -W
OBJS = main.o
CC = gcc

test : ${OBJS}
	$(CC) ${CFLGS} -o $@ ${OBJS}

.PHONY:clean

clean:
	-rm -f ${OBJS} test
