#include <stdio.h>
#include <stdlib.h>




void print_lines(int count) {
    for (int i = 0; i < count; i++) {
        printf("-");
    }
    puts("\n");
 }

FILE *read_file(char filename[], char *buffer) {
    FILE* file = fopen(filename, "r");
    return file;
}


int main() {
    int c;
    int count = 0;
    int number_words[20];
    
    const int tab_stop = 8;
    
    char line[256];

    FILE *fptr = read_file("yay.txt", line);

    while ((c = fgetc(fptr)) != EOF) {
        // ++count;
        // printf("%c\n", c);
        if (c == '\t') {
            printf("yay");           
            ++number_words[count-1];
            // printf("%d\n", count - 1);
            count = 0;
        }
    }

    // for (int i = 0; i < sizeof(number_words); ++i) {
    //     printf("%d\n", i);
    // }
    
}