CFLAGS = -Wall -Wextra -pedantic -g
OBJ = main.c

all: build run

build:
	gcc $(CFLAGS) $(OBJ) -o main.o

run:
	./main.o

clean:
	rm -rf *.o
