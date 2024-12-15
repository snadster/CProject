SAN_FLAGS = -fsanitize=address,undefined,leak
CFLAGS = -Wall -g $(SAN_FLAGS)
LDLIBS = -lm
LDFLAGS = $(SAN_FLAGS)

OBJS = LinkedList.h Graph.h cycleDetection.h main.c

detectCycles: $(OBJS)
	$(CC) $(LDFLAGS) -o  $@  $^  $(LDLIBS)
	
.PHONY: clean
clean:
	rm -f *.o detectCycles
