#include <stdio.h>
#include <string.h> // To get strcpy()
#include <stdlib.h> // To get exit()

#define MAX_STRING_SIZE 1024

int main (int argc, char *argv[])
{

  // Declare an array of chars.
  char a_string [MAX_STRING_SIZE];

  // Copy the string from the command line to a_string.
  strcpy (a_string, argv[1]);

  // Print out the copied string.
  printf ("The string that was copied was \"%s\".\n", a_string);

  // Exit cleanly
  exit (0);
} 