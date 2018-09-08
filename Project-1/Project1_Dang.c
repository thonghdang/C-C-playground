#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SIZE_STRING 1024

int fsize (char filename []);

int main(int argc, char *argv[])
{
    
    FILE *f;
    
    // Declare an array of char to store.
    char filename[MAX_SIZE_STRING]; 

    // Open the test file.
    strcpy (filename, argv[1]);
    f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1);
    }

    // Move the pointer the third character of the file name 
    fseek(f, fsize(filename) - 1, SEEK_SET);

    // Print character from the file.
    printf("The character in the file is: %c", fgetc(f));

    printf("\n");

    // Print the size of the file.
    printf("The file size is: %d", fsize(filename));

    return 0;
}

int fsize (char filename[])
{
    struct stat st;

    if (stat(filename, &st)) {
        return -1;
    }

    return st.st_size;
}
