#include <stdio.h>

#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word */

/* count lines, words and characters in input */
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = 0;
    printf ("Please input your message: ");
    while ( (c = getchar())!= EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if ( c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
        printf ("New lines: %d\n", nl);
        printf ("New words: %d\n", nw);
        printf ("New characters: %d\n", nc);
    }
    return 0;
}
