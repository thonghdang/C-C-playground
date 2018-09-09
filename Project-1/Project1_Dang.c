#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SIZE_STRING 1024

int fsize (char filename []);

int main(int argc, char *argv[])
{
    
    FILE *f;
    char filename[MAX_SIZE_STRING]; 
    char right_pos, left_pos;
    int step;

    strcpy (filename, argv[1]);
    f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1);
    }

    step = 0;
    while (step <= fsize(filename))
    {
        fseek(f, step++, SEEK_SET);
        right_pos = fgetc(f);
        fseek(f, fsize(filename) - step, SEEK_SET);
        left_pos = fgetc(f);
        if (right_pos != left_pos)
        {
            printf("%s is not a palindrome. It is differs at char %c and %c", filename, right_pos, left_pos);
            exit(-1);
        }
        else {
            step++;
        }
        
    }
    printf("%s is a palindrome", filename);
    
    exit(0);
}  
   

int fsize (char filename[])
{
    struct stat st;

    if (stat(filename, &st))
    {
        return -1;
    }

    return st.st_size;
}

