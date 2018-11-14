#include <stdio.h>
#include <stdlib.h>

#include "count_list.h"

#define MAX_LEN 1024

int main (int argc, char *argv[])
{

  /* No need to copy the string since we aren't altering it. */
  char *input_file = argv[1];
  FILE *the_file;
  char a_word[MAX_LEN];
  char sort_type;
  
  if ( (the_file = fopen (input_file, "r")) == NULL) {
    /* Opening the file failed. */
    fprintf (stderr, "Usage: word_count <file name>\n");
    exit (-1);
  }

  /* Create a word list. */
  initialize_word_list();

  /* Use fcanf to grab words (any collection of chars surrounded by
     whitespace).  If they are already in the list, increment the
     count.  Otherwise, add to list. */
  while (fscanf(the_file, "%s", a_word) != EOF) {
    if (in_list (a_word)) {
      increment_word_count (a_word);
    } else {
      add_word (a_word);
    }
  }

  /* Output the word / frequency list in the desired format. */
  printf ("Processing finished.\n");
  printf ("Enter 'f' to display by frequency, 'l' to display lexicographically,\n");
  printf ("and any other key for default order.\n");
  scanf ("%c", &sort_type);
  printf ("\n");

  if (sort_type == 'f') {
    sort_by_frequency();
  } else if (sort_type == 'l') {
    sort_lexicographically();
  }
    
  print_list();

  cleanup_list();

  return 0;
}
    
  
