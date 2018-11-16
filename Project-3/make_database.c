#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database_func.h"
#define MAX_SNIPPETS_NUM 1000
#define MAX_SNIPPET_LEN 1000

char snippets_num[10];
int num_snippet;
char snippets_arr[MAX_SNIPPETS_NUM][MAX_SNIPPET_LEN];

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

 void read_snippets (FILE *f)
    {
    int snippets_num;

    snippets_num = 0;
    while ( fgets(snippets_arr[snippets_num], MAX_SNIPPET_LEN, f) == NULL) {
        snippets_arr[snippets_num][strlen(snippets_arr[snippets_num]) - 1] = '\0';
        printf("%s\n", snippets_arr[snippets_num]);
        snippets_num++;
    }
}