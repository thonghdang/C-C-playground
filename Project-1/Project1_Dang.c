/*
 * Author: Thong Dang.
 * Date: 09/09/2018
 * CS 250 - 01.
 * Professor: Bob Matthews.
 * Project 1: Detecting Palindromic Files.
 * This program is used to determine if the entire contents of a text file is a 
 single palindrome or not.
 */

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
    int left_pos;

    // Copy and store the input file into the filename array.
    strcpy (filename, argv[1]);

    // Open and read in the file.
    fb = fopen(filename, "r");
    
    // If the file is not exist, print the error message.
    if(fb == NULL)
    {
        printf("Error, Cannot open file.\n");
        exit(-1); // Terminate the program. 
    }

    /* Run a loop through the file, compare characters read from the left and the
       right to see if they are the same. 
     */
    for (left_pos = 0; left_pos < fsize(filename); left_pos++)
    {
      fseek(fb, left_pos, SEEK_SET);
      left_char = fgetc(fb);
      fseek(fb, fsize(filename)-1-left_pos, SEEK_SET);
      right_char = fgetc(fb);

      /* If the left character is not the same with the right, print the error message
	with the postition of the differences and terminate the program.
       */ 
      if(left_char != right_char)
      {
	printf("%s is not a palindrome. It differs at characters %d and %d.\n",
	        filename, left_pos, fsize(filename)-1-left_pos);
	exit(-1); // Terminate the program.
      }               
    }
    
    printf("%s is a palindrome.\n", filename);
   
    exit(0); // Exit cleanly.
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

