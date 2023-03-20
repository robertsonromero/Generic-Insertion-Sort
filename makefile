#I pledge my honor that I have a bided by the Stevens honor system. 
# - Robertson Romero

CC = gcc
CFLAGS=-c -Wall -g

all: isort 
isort: main.o utils.o insertion.o
	$(CC) main.o utils.o insertion.o
main.o: main.c
	$(CC) $(CFLAGS) main.c
utils.o: utils.c
	$(CC) $(CFLAGS) utils.c
insertion.o: insertion.c
	$(CC) $(CFLAGS) insertion.c

clean:
	rm -rf *.o a.out isort