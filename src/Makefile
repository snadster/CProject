
SAN_FLAGS = -fsanitize=address ,undefined ,leak
CFLAGS = -Wall  -g -O2 $(SAN_FLAGS)
LDLIBS = -lm  -lstuff
CPPFLAGS = -Ipath/to/stuff/include
LDFLAGS = -Lpath/to/stuff/lib $(SAN_FLAGS)

OBJS = LinkedList.h Graph.h cycleDetection.h main.c

prog: $(OBJS)
	$(CC) $(LDFLAGS) -o  $@  $^  $(LDLIBS)
	
.PHONY: clean
clean:
	rm -f *.o prog