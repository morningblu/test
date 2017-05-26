#TARGETS
OBJS := doubly_linked_list
TARGET = main.o
TARGET += doubly_linked_list.o

#compile
CC = gcc
CFLAGS = -g -Wall

$(OBJS) : $(TARGET)
	$(CC) $(CFLAGS) -o $@ $(TARGET)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

doubly_linked_list.o : doubly_linked_list.c
	$(CC) $(CFLAGS) -c doubly_linked_list.c

.PHONY:
	clean

clean:
	-rm -f $(TARGET) $(OBJS)
