.DEFAULT_GOAL	:= all

CC = gcc

linked-list:
	$(CC) -c src/$@.c -o build/$@.o

red-black-tree:
	$(CC) -c src/$@.c -o build/$@.o

stack:
	$(CC) -c src/$@.c -o build/$@.o

OBJ = build/stack.o

main: linked-list red-black-tree stack
	$(CC) -o build/$@ src/$@.c $(OBJ)

all: linked-list red-black-tree stack
