#include <stdio.h>

main() {  
    int c;
    while (c = getchar() != EOF) {
        if(c == 9) {
            printf("yay");
            continue;
        } else if (c == 8){
            printf("\\b");
            continue;           
        } else if (c == 92) {
            printf("\\\\");
            continue;
        }
        putchar(c);       
    }
    puts("\n");  
}