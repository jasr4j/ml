CC = gcc
CFLAGS = -O2 -Wall -Wextra

all: ml

ml: ml.o
	$(CC) $(CFLAGS) ml.o -o ml

ml.o: ml.c
	$(CC) $(CFLAGS) -c ml.c

clean:
	rm -f *.o ml