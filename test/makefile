CFLGS = -g -W
OBJS = main.o

test : ${OBJS}
	gcc ${CFLGS} -o $@ ${OBJS}

.PHONY:clean

clean:
	-rm -f ${OBJS} test
