/* Declaring some constants for storing dictionary */
// #define MAX_DICT_LINES 52875
// #define MAX_WORD_LEN 30

#define MAX_DICT_LINES 12
#define MAX_WORD_LEN 30

/* Declaring some constants for storing user input. */
#define MAX_LINE_LENGTH 1024
#define MAX_WORD_SIZE 100

/* Define macro to calculate the distance. */
// #define MIN(x,y) (((x)<(y))?(x):(y))

/* Some function prototypes. */
void make_dict(char *);
void spell_check(char *);
unsigned int distance (const char *, const char *);
