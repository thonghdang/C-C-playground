#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int fsize (char filename []);

int main(int argc, char *argv[])
{
    
    FILE *f;
    char c; 

    // Open the test file.
    f = fopen("test.txt", "r");
    if(f == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(1);
    }

    printf("File size is %d", fsize("test.txt"));

    
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
