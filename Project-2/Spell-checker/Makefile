# Makefile for spell checker
main:	main.o dictionary.o
	gcc -o main main.o dictionary.o

main.o:	  main.c dictionary.h
	gcc -c -Wall --pedantic main.c

dictionary.o:	dictionary.c dictionary.h
	gcc -c -Wall --pedantic dictionary.c

all:	main

clean:	
	rm -f dictionary.o main.o main
