
/*
 * CS 250
 * Project 2: A Simple Spell-Checker
 * Author: Thong Dang
 * Date: November 7th, 2018
 * Description: This program is a simple spell check user input.
 */

/* Pre-processor directives */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"


/* Declaring constants */
// #define MAX_LINE_LENGTH 1024
// #define MAX_WORD_SIZE 100
// #define MIN(a,b) (((a)<(b))?(a):(b))


/* Declaring function prototype */
//unsigned int distance (const char *a, const char *b);


/* Main module */
int main ()
{
  extern int words_num;
  extern char dictionary[MAX_LINES][MAX_WORD_LEN];

  // Create the dictionary in a 2D array
  make_dict ("dictionary.txt");
  char line[MAX_LINE_LENGTH];
  printf ("Enter a string: ");

  // Take user's input
  fgets (line, MAX_LINE_LENGTH, stdin);
  line[strlen(line)-1] = '\0';
  char * word;
  word = strtok (line, " ");
  int min_dist;
  int i;
  char*correct_word;
  
 
  while (word != NULL)
    { 
      min_dist= MAX_WORD_SIZE;
      
      for (i=0; i<words_num; i++) {
                
	if ((distance(dictionary[i], word))==0)
	  {
	    correct_word=word;
	    
	    break;
	  } 
	else
	{
	    int dist = distance (word, dictionary[i]);
	    
	    if (dist < min_dist) {
	      min_dist = dist;
	      correct_word=dictionary[i];
	    }
	  }
  
      }
      if (correct_word == word) {
	printf("%s ",correct_word);
      } else {
	printf ("*%s* ", correct_word);
      }
      word = strtok (NULL, " ");
    }
}




      



  
       
            	 

