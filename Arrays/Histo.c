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
    
    char line[256];

    FILE *fptr = read_file("yay.txt", line);
    // int i = 0;
    // while ((c = fgetc(fptr)) != EOF)
    //     printf("%c", c);
    
    

    while ((c = fgetc(fptr)) != EOF) {
        ++count;
        // printf("%c\n", c);
        if (c == ' ' || c == '\t' || c == '\n') {           
            ++number_words[count-1];
            // printf("%d\n", count - 1);
            count = 0;
        }
    }

    for (int i = 0; i < sizeof(number_words); ++i) {
        printf("%d\n", i);
        // if (i < 10) {
        //     printf("0%d| %d \n", i, number_words[i]);
        // } else {
        //     printf("%d| %d \n", i, number_words[i]);
        // }
    }

    // printf("%d", count);
    // for (int i = 0; i < 20; ++i) {
    //     if (i < 10) {
    //         printf("0%d| %d \n", i, number_words[i]);
    //     } else {
    //         printf("%d| %d \n", i, number_words[i]);
    //     }
        
    // //     print_lines(number_words[i]);
    // }
    
}