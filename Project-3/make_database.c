#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database_func.h"

char snippets_num[10];
int num_snippet;

void read_snippets (FILE *);

int main (int argc, char *argv[])
{
    FILE *the_file;
    char *file_input = argv[1];
    the_file = fopen(file_input, "r");

    if (the_file == NULL) {
    /* Opening the file failed. */
    fprintf (stderr, "Usage: database <file name>\n");
    exit (-1);
    }

    read_snippets(the_file);


    return 0;
}
