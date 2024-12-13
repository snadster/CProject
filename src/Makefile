SAN_FLAGS = -fsanitize=address,undefined,leak
CFLAGS = -Wall -g $(SAN_FLAGS)
LDLIBS = -lm
LDFLAGS = $(SAN_FLAGS)

OBJS = LinkedList.o Graph.o cycleDetection.o main.o

detectCycles: $(OBJS)
	$(CC) $(LDFLAGS) -o  $@  $^  $(LDLIBS)
	
.PHONY: clean
clean:
	rm -f *.o detectCycles
