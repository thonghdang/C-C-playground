
/* CS 250
 * Project 2: A Simple Spell-Checker
 * Author: Thong Dang
 * Date: November 7th, 2018
 * Description: This program checks user input spelling words.
 * Main module.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

/* Declare constant to store user input.*/
#define MAX_LINE_INPUT 1024

/* Main module */
int main ()
{

  /* Read the dictionary into array. */
  make_dict ("/usr/share/dict/cracklib-small");

  char input[MAX_LINE_INPUT];
  printf ("Input a string of character: ");

  /* Prompt user input and store into array. */
  fgets (input, MAX_LINE_INPUT, stdin);
  input[strlen(input)-1] = '\0';

  /* Perform spell check on the input */
  spell_check (input);

  return 0;
}




      



  
       
            	 

