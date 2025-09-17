CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra

all: mv

mv: mv.o parser.o
	$(CC) $(CFLAGS) mv.o parser.o -o mv

mv.o: mv.c
	$(CC) $(CFLAGS) -c mv.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

clean:
	rm -f *.o mv