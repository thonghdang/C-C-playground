#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SIZE_STRING 1024

int fsize (char filename []);

int main(int argc, char *argv[])
{
    
    FILE *fb;
    char filename[MAX_SIZE_STRING]; 
    char right_char, left_char;

    strcpy (filename, argv[1]);
    fb = fopen(filename, "r");
    if(fb == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1);
    }

    int i;
    for (i = 0; i < fsize(filename); i++)
    {
      fseek(fb, i, SEEK_SET);
      left_char = fgetc(fb);
      fseek(fb, fsize(filename)-1-i, SEEK_SET);
      right_char = fgetc(fb);
      
      if(left_char != right_char)
      {
	printf("%s is not a palindrome. It differs at characters %c and %c \n",
		filename, left_char, right_char);
	exit(-1);
      }
               
    }
    printf("%s is a palindrome.\n", filename);
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

