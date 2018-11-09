
/* CS 250
 * Project 2: A Simple Spell-Checker
 * Author: Thong Dang
 * Date: November 7th, 2018
 * Description: This program checks user input spelling words.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"


/* Main module */
int main ()
{

  /* Read the dictionary into array. */
  make_dict ("dictionary.txt");

  char input[MAX_LINE_LENGTH];
  printf ("Input a string of character: ");

  /* Prompt user input and store into array. */
  fgets (input, MAX_LINE_LENGTH, stdin);
  input[strlen(input)-1] = '\0';

  /* Perform spell check on the input */
  spell_check (input);
}




      



  
       
            	 

