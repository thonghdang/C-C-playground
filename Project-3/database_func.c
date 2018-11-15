#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database_func.h"

#define MAX_SNIPPETS_NUM 100 
#define MAX_SNIPPET_LEN 100


struct person {
    char *name;
    char *street_address;
    char *city;
    char *state;
    char *zip_code;
};

static struct person *person_list[MAX_SNIPPETS_NUM];
static int person_count;
char snippets_arr[MAX_SNIPPETS_NUM][MAX_SNIPPET_LEN];

void read_snippets (FILE *f)
{
    int snippets_num;

    snippets_num = 0;
    while ( fgets(snippets_arr[snippets_num], MAX_SNIPPET_LEN, f) == NULL) {
        snippets_arr[snippets_num][strlen(snippets_arr[snippets_num]) - 1] = '\0';
        snippets_num ++;
    }
}

void snippet_to_struct (char arr[MAX_SNIPPETS_NUM][MAX_SNIPPET_LEN])
{
    int i;
    
}

void initiate_snippet_count(FILE* f)
{
    char temp[MAX_SNIPPETS_NUM];
    if ( (fgets(temp, MAX_SNIPPETS_NUM, f)) == NULL) {
        printf("There is no snippet numbers in file. \n");
        person_count = 0;
    } else {
        person_count = atoi(temp);
    }   
}

void list_snippet (struct person * person_list[MAX_SNIPPET_LEN])
{
    int i;
    for (i = 0; i < person_count; i++) {
        printf("%s\n", person_list[i]->name);
        printf("%s\n", person_list[i]->street_address);
        printf("%s, ", person_list[i]->city);
        printf("%s %s\n", person_list[i]->state, person_list[i]->zip_code);
        printf("\n");
    }
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




