CC = gcc
CFLAGS = -O2 -Wall -Wextra

all: linear

linear: linear.o parser.o
	$(CC) $(CFLAGS) linear.o parser.o -o linear

linear.o: linear.c
	$(CC) $(CFLAGS) -c linear.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

clean:
	rm -f *.o linear