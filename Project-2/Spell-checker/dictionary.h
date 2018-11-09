/* Declaring some constants */
//#define MAX_LINES 52875
//#define MAX_WORD_LEN 30

#define MAX_LINES 12
#define MAX_WORD_LEN 30

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_SIZE 100

#define MIN(x,y) (((x)<(y))?(x):(y))

void make_dict(char *);

void spell_check(char *);

unsigned int distance (const char *, const char *);
