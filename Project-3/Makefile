database:	database_func.o make_database.o
	gcc -o database database_func.o make_database.o

database_func.o:	database_func.c database_func.h
	gcc -c -Wall --pedantic database_func.c

make_database.o:	make_database.c database_func.h
	gcc -c -Wall --pedantic make_database.c 

all: database

clean: 
	rm -f make_database.o database_func.o database database.tar

tarball:	make_database.c database_func.c database_func.h Makefile
	tar -cf database.tar make_database.c database_func.c database_func.h Makefile