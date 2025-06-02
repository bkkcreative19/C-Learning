#include <stdio.h>

main() {
    int blank_counter = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if(c == 95) {
            ++blank_counter;

            if (blank_counter > 1) {
                continue;
            }
        } else if (c == 10){
            blank_counter = 0;
            
        } else if (blank_counter >= 1 && c != 95) {
            blank_counter = 0;
        }
        putchar(c);       
    }
    puts("\n");
   
}