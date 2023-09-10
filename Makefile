.DEFAULT_GOAL	:= all

CC = gcc

linked-list.o:
	$(CC) -c src/linked-list.c -o build/$@

red-black-tree.o:
	$(CC) -c src/red-black-tree.c -o build/$@

stack.o:
	$(CC) -c src/stack.c -o build/$@

OBJ = build/stack.o

main: linked-list.o red-black-tree.o stack.o
	$(CC) -o build/$@ src/$@.c $(OBJ)

all: main
