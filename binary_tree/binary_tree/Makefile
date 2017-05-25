#compile target
OBJS := binary_tree
TARGET = main.o
TARGET += binary_tree.o

#compile flags
CC	= gcc
CFLAGS = -g -Wall

$(OBJS) : $(TARGET)
	$(CC) $(FLAGS) -o $@ $(TARGET)

main.o : main.c
	$(CC) $(FLAGS) -c main.c

binary_tree.o : binary_tree.c
	$(CC) $(FLAGS) -c binary_tree.c

.PHONY:
	clean

clean:
	-rm -f $(TARGET) $(OBJS)
