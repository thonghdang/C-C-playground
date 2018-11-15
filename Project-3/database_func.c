#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database_func.h"

#define MAX_SNIPPETS 100


struct person {
    char *name;
    char *street_address;
    char *city;
    char *state;
    char *zip_code;
};

static struct person *person_list[MAX_SNIPPETS];
static int person_count;

void initiate_snippet_count(FILE* f)
{
    char temp[MAX_SNIPPETS];
    if ( (fgets(temp, MAX_SNIPPETS, f)) == NULL)
    {
        printf("There is no snippet numbers in file. \n");
        person_count = 0;
    } else {
        person_count = atoi(temp);
    }   
}

int list_snippet (struct person * person_list[])
{
    int i;
    for (i = 0; i < person_count; i++)
    {
        printf("%s\n", person_list[i]->name);
        printf("%s\n", person_list[i]->street_address);
        printf("%s, ", person_list[i]->city);
        printf("%s %s\n", person_list[i]->state, person_list[i]->zip_code);
        printf("\n");
    }
    return 1;
}


int add_snippet (char *name, char *street_address, char *city, char *state, char *zip_code)
{
    struct person *new_person =
    (struct person *) malloc (sizeof (struct person));

    new_person->name = (char *) malloc (strlen (name) + 1);
    strcpy (new_person->name, name);

    /* Add new person info. */
    new_person->street_address = (char *) malloc (strlen (street_address) + 1);
    strcpy (new_person->street_address, street_address);

    new_person->city = (char *) malloc (strlen (city) + 1);
    strcpy (new_person->city, city);

    new_person->state = (char *) malloc (strlen (state) + 1);
    strcpy (new_person->state, state);

    new_person->zip_code = (char *) malloc (strlen (zip_code) + 1);
    strcpy (new_person->zip_code, zip_code);

     /* Add the person to the list. */
    person_list[person_count] = new_person;
  
    /* Increase person count */
    person_count++;

    return 1;
}




