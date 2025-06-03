#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalidrome(char string[]) {
    int beginning = 0;
    int end = strlen(string) - 2;

    while(beginning <= end) {
        if(string[beginning] == string[end]) {
            ++beginning;
            --end;
        } else {
            return false;
        }       
    }
    
    return true;
}


int main() {

    char string[40];
    printf("Input a string to be checked: \n");

    fgets(string, sizeof(string), stdin);
    // isPalidrome(string);
    if(isPalidrome(string)) {
        printf("Yes it is a palidrome");
    } else {
        printf("No this is not a palidrome");
    }
    // printf(string);

    return 0;
}