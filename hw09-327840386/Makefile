CC = gcc

CFLAGS = -Wall -g
DEPS = cities.h adjlist.h dijkstra.h 
OBJ = main.o cities.o adjlist.o dijkstra.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) main
