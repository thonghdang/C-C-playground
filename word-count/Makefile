#Make file for word_count.
word_count:  count_list.o word_count.o
	gcc -o word_count count_list.o word_count.o

count_list.o:  count_list.c count_list.h
	gcc -c count_list.c -Wall --pedantic

word_count.o:  word_count.c count_list.h
	gcc -c word_count.c -Wall --pedantic

all:  word_count

clean:
	rm -f count_list.o word_count.o word_count
