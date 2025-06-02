#include <stdio.h>


main() {
    int c; 
    int i; 
    int number_of_white_space = 0; 
    int number_of_other_characters = 0;

    int ndigit[10];

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++number_of_white_space;
        } else {
            ++number_of_other_characters;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", number_of_white_space, number_of_other_characters);

}