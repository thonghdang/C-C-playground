#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int fsize (char filename []);

int main(int argc, char *argv[])
{
    // Open the test file.
    FILE *f;
    int c; 

    f = fopen("test.txt", "r");

    fseek (f, 1, SEEK_SET);
    
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
