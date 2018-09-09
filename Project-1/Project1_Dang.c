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
    char right_char, left_char;
    int step;

    strcpy (filename, argv[1]);
    f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1);
    }

    for (step = 0; step <= fsize(filename); step++)
    {
        fseek(f, step, SEEK_SET);
        left_char = fgetc(f);
        printf("Left char: %c\n", left_char);
    }

    // step = 0;
    // while (step <= fsize(filename))
    // {
    //     fseek(f, step + 1, SEEK_SET);
    //     left_char = fgetc(f);
    //     fseek(f, fsize(filename) - 1 - step, SEEK_SET);
    //     right_char = fgetc(f);
    //     if (left_char != right_char)
    //     {
    //         printf("%s is not a palindrome. It is differs at char %c and %c", 
    //                 filename, left_char, right_char);
    //         exit(-1);
    //     }
    //     else {
    //         step++;
    //     }     
    // }
    // printf("%s is a palindrome", filename);
    
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

