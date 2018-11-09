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

<<<<<<< HEAD
tarball:    main.c dictionary.c dictionary.h Makefile
	tar -c -f main.tar main.c dictionary.c dictionary.h Makefile


=======
tarball:	main.c dictionary.c dictionary.h Makefile
	tar -c spellchecker.tar main.c dictionary.c dictionary.h Makefile
>>>>>>> c63127e7d48b3fcafe4530ea89a0033cce685538
