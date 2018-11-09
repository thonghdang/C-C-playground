/* Dictionary module */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

static int number_of_words;
char dict_array[MAX_DICT_LINES][MAX_WORD_LEN];

/* Function to read dictionary into 2D array*/
void make_dict (char * dict_name)
{
  number_of_words = 0;
  
  FILE * file_dict;
  file_dict = fopen (dict_name, "r");  

  while (fgets (dict_array[number_of_words], MAX_WORD_LEN, file_dict)!= NULL) {
    dict_array[number_of_words][strlen(dict_array[number_of_words])-1] = '\0';
    number_of_words++; 
  }
}

/* Function to spell check the user input.*/
void spell_check (char * input)
{
  char * tokenized_words;
  char * correct_words;
  int i;
  int min_distance;

  tokenized_words = strtok (input, " ");
  while (tokenized_words != NULL) 
  { 
    min_distance = MAX_WORD_SIZE;
    for (i = 0; i < MAX_DICT_LINES; i++) 
    {
      if ((distance(dict_array[i], tokenized_words))==0) 
      {
        correct_words= tokenized_words;
        break;
      } 
      else 
      {
        int dist = distance (tokenized_words, dict_array[i]);

        if (dist < min_distance) {
	        min_distance = dist;
	        correct_words =dict_array[i];
        }
	    }
    }

    if (correct_words == tokenized_words)
    {
      printf("%s ",correct_words);
    } 
    else 
    {
      printf ("*%s* ", correct_words);
    }
      
    /* Get to the next words. */
    tokenized_words = strtok (NULL, " ");
  }
  printf(" \n");
}


/* Calculate the Levenstein distance between a and b. */
unsigned int distance (const char *a, const char *b)
{
  unsigned int a_len = strlen(a);
  unsigned int b_len = strlen(b);
  /* The base case occurs when one string is empty. */
  if (a_len == 0) {
    return b_len;
  }
  if (b_len == 0) {
    return a_len;
  }
  /* The recursive case. Construct new strings representing the head
     of each string, by truncating the last char of the strings. */
  char a_head[MAX_WORD_SIZE], b_head[MAX_WORD_SIZE];
  strcpy (a_head, a);
  strcpy (b_head, b);
  /* Truncate string length by 1. */
  a_head[a_len - 1] = '\0';
  b_head[b_len - 1] = '\0';
  
  int head_dist;
  /* Calculate the distance between the heads. */
  if (a[a_len - 1] == b[b_len - 1]) {
    head_dist = distance (a_head, b_head);
  } else {
    head_dist = 1 + distance (a_head, b_head);
  }
  /* Now, calculate the distance between each string and the head of
     the other. */
  int ahead2b_dist = 1 + distance (a_head, b);
  int bhead2a_dist = 1 + distance (a, b_head);
  /* The Levenshtein distance is the minimum of these three quantities.
     MIN is a macro. You ll need to write this. */
  return MIN(head_dist, MIN(ahead2b_dist, bhead2a_dist));
}
