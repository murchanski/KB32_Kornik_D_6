CC = gcc
CFLAGS = -Wall -pthread

all: your_program

your_program: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o your_program
