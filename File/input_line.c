#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main() {
    int c;
    int new_line;
    int new_word;
    int new_character;
    int state;

    state = OUT;
    new_line = 0;
    new_word = 0;
    new_character = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            puts("\n");
        }
        
        /*++new_character;
        if (c == '\n')
            ++new_line;
        if (c == ' ' || c == '\n' || c == '\t')
            
        else if (state == OUT) {
            state = IN;
            ++new_word;
        }*/
    }
    /*printf("%d %d %d\n", new_line, new_word, new_character);*/
}