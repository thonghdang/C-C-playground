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
    char begin, end;
    int step, head_point, tail_point;

    strcpy (filename, argv[1]);
    f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1);
    }

    // printf("Size %d\n", fsize(filename));
    // head_point = fseek(f, 3, SEEK_SET);
    // begin = fgetc(f);
    // tail_point = fseek(f, fsize(filename) - 1, SEEK_SET);
    // end = fgetc(f);
    // printf("Head: %c\n", begin);
    // printf("End: %c", end);

    step = 1;
    while (begin < end)
    {
        
        fseek(f, step + 1, SEEK_SET);
        begin = fgetc(f);
        fseek(f, fsize(filename) - step, SEEK_SET);
        end = fgetc(f);
        step++;
        printf("Head %c\t Tail %c\n", begin, end);
        if (begin == end)
        {
            printf("This is a palindrome.");
        }
        else 
        {
            printf("This is not....")
        }
    }

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

