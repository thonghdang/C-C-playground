#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "count_list.h"

/* The maximum number of entries in a word list. */
#define MAX_WORDS 10000

/* What one entry looks like. */
struct entry {
  char *word;
  int count;
};

/* The list */
static struct entry *word_list[MAX_WORDS];

/* The number of entries currently in the list. */
static int n_words;

/* Initially, the list has no entries in it. */
void initialize_word_list()
{
  n_words = 0;
}


/* Search for a word in the list.  Return true if the
   word is in the list, false otherwise. */
int in_list (char *word)
{
  int i;
  for (i = 0; i < n_words; i++) {
    if (strcmp (word, word_list[i]->word) == 0) {
      return 1;
    }
  }

  return 0;
}


/* Add a new word to the list, and initialize its count to 0.  Return
   1 on success, 0 on failure. */
int add_word (char *word)
{
  if (n_words == MAX_WORDS) {
    /* Failed to add the word to the list. */
    return 0;
  }

  /* Create a new entry in the list. 
     First, allocate memory for the entry. */
  struct entry *new_entry =
    (struct entry *) malloc (sizeof (struct entry));
  
  /* Now, allocate memory for the word, and copy the word into this
     new memory. */
  new_entry->word = (char *) malloc (strlen (word) + 1);
  strcpy (new_entry->word, word);
  
  /* Set the word count to 1. */
  new_entry->count = 1;
  
  /* Add the word to the list. */
  word_list[n_words] = new_entry;
  
  /* Up word count */
  n_words++;
  
  /* We succeeded in adding the word to the list. */
  return 1;
}


/* If the word pointed to by word is in the list, increment its count
   and return the new count.  If it is not in the list, return 0. */
int increment_word_count (char *word)
{
  int i;
  
  for (i = 0; i < n_words; i++) {
    if (strcmp (word, word_list[i]->word) == 0) {
      return ++word_list[i]->count;
    }
  }
  return 0;
}


/* Print all the words and their frequences. */
void print_list ()
{

  int i;
  
  printf ("Word\tFrequency\n");
  printf ("----\t---------\n");
  for (i = 0; i < n_words; i++) {
    printf ("%s\t%9d\n", word_list[i]->word, word_list[i]->count);
  }

}


/* Compare two entries by their frequency, returning a positive value
   if e1 comes before e2, a negative value if e1 comes after e2, and 0
   otherwise.

   A bit of type magic is being performed here...  This function is
   receiving pointers to elements of the array word_list.  Those
   elements are themselves pointers.  So, we convert the (void *)
   parameters to (struct entry **) pointers, and then dereference them
   to get the pointers to the entries.

   The reason we have to do this is because qsort (below) uses this
   function, and requires it to have the given signature. */
static int compare_by_frequency (const void *a, const void *b)
{
  struct entry *e1 = *(struct entry **) a;
  struct entry *e2 = *(struct entry **) b;
  return e1->count - e2->count;
  
  /* Normally, a C programmer would do the type casting and
     subtraction without the user of intermediate variables:

  return (*(struct entry **)e1)->count - (*(struct entry **)e2)->count;
  
  */
}

/* Compare two entries lexicographically, returning a positive value
   if e1 comes before e2, a negative value if e1 comes after e2, and 0
   otherwise. */
static int compare_lexicographically (const void *e1, const void *e2)
{
  return strcmp (
		 (*(struct entry **)e1)->word,
		 (*(struct entry **)e2)->word);
}

  
/* Sort the list by word frequency using the quiksort algorithm. */
void sort_by_frequency ()
{
  qsort (word_list, /* pointer to first element of array */
	 (size_t) n_words,   /* number of elements in the array */
	 sizeof (struct entry *), /* the size of one element of the
				     array */
	 compare_by_frequency); /* the function to use to determine if
				   elements are out of order */
}

/* Sort the list lexicographically using the quicksort algorithm. */
 void sort_lexicographically ()
 {
   qsort (word_list,
	  (size_t) n_words,
	  sizeof (struct entry *),
	  compare_lexicographically);
 }


/* Release all the memory occupied by the list. */
void cleanup_list()
{
  int i;

  for (i = 0; i < n_words; i++) {
    free (word_list[i]->word);
    free (word_list[i]);
  }
}



