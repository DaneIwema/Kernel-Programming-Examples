CC = gcc
CFLAGS = -Wall -g

all: test

test: test.o stack.o
	$(CC) $(CFLAGS) -o test test.o stack.o

test.o: test.c dslib.h
	$(CC) $(CFLAGS) -c test.c

stack.o: stack.c dslib.h
	$(CC) $(CFLAGS) -c stack.c