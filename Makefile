CC = gcc
CFLAGS = -Wall -pedantic -ansi
LDFLAGS = -lm
BIN = freq.exe
OBJ = main.o overlap.o transmitter.o node.o intstack.o errors.o

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BIN): $(OBJ)
		$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm $(OBJ)

