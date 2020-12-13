all: cripto

CC=g++
CFLAGS = -c -Wall

cripto: cripto.o cripto_functions.o
	$(CC) cripto.o cripto_functions.o -o cripto
cripto.o: cripto.cc
	$(CC) $(CFLAGS) cripto.cc
cripto_functions.o: cripto_functions.cc
	$(CC) $(CFLAGS) cripto_functions.cc
clean:
	$(RM) *.o cripto cripto_functions