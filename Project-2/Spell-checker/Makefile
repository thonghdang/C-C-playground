# Makefile for spell checker
spellcheck:	main.o dictionary.o 
	gcc -o spellcheck main.o dictionary.o

main.o:	  main.c dictionary.h
	gcc -c -Wall --pedantic main.c

dictionary.o:	dictionary.c dictionary.h
	gcc -c -Wall --pedantic dictionary.c

all:	spellcheck

clean:	
	rm -f dictionary.o main.o spellcheck spellcheck.tar

tarball:    main.c dictionary.c dictionary.h Makefile
	tar -cf spellcheck.tar main.c dictionary.c dictionary.h Makefile



