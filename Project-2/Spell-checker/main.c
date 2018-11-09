
/* CS 250
 * Project 2: A Simple Spell-Checker
 * Author: Thong Dang
 * Date: November 7th, 2018
 * Description: This program spell check user input.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

//int words_num;
char dictionary[MAX_LINES][MAX_WORD_LEN];

/* Main module */
int main ()
{

  // Read the dictionary into array
  make_dict ("dictionary.txt");

  char input[MAX_LINE_LENGTH];
  printf ("Enter a string: ");

  // Prompt user input and store into array
  fgets (input, MAX_LINE_LENGTH, stdin);
  input[strlen(input)-1] = '\0';

  char * unchecked_words;
  int min_distance;
  int i;
  char * correct_words;

  // Extract word by word from user input.
  unchecked_words = strtok (input, " ");

  
  while (unchecked_words != NULL) 
  { 
    min_distance = MAX_WORD_SIZE;
    for (i = 0; i < MAX_LINES; i++) 
    {
      if ((distance(dictionary[i], unchecked_words))==0) 
      {
        correct_words= unchecked_words;
        break;
      } 
      else 
      {
        int dist = distance (unchecked_words, dictionary[i]);

        if (dist < min_distance) {
	        min_distance = dist;
	        correct_words =dictionary[i];
        }
	    }
    }

    if (correct_words == unchecked_words)
    {
      printf("%s ",correct_words);
    } 
    else 
    {
      printf ("*%s* ", correct_words);
    }
      
    // Get to the next words.
    unchecked_words = strtok (NULL, " ");
  }

  printf(" \n");
}




      



  
       
            	 

