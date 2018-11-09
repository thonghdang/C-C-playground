# Makefile for spell checker
spellchecker:	main.o dictionary.o
	gcc -o spellchecker main.o dictionary.o

main.o:	  main.c dictionary.h
	gcc -c -Wall --pedantic main.c

dictionary.o:	dictionary.c dictionary.h
	gcc -c -Wall --pedantic dictionary.c

all:	main

clean:	
	rm -f dictionary.o main.o spellchecker
