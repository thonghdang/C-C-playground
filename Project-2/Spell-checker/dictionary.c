/* Module of the dictionary */

// Pre-processor directives
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

int words_num;
char dictionary[MAX_LINES][MAX_WORD_LEN];

void make_dict (char *dict_name)
{
  words_num = 0;
  
  FILE *dict;
  dict = fopen (dict_name, "r");  
  while (fgets (dictionary[words_num], 30, dict)!= NULL) {
    dictionary[words_num][strlen(dictionary[words_num])-1] = '\0';
    words_num++; 
  }
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
