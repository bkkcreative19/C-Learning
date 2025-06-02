#include <stdio.h>


int get_input_length(char input_string[]) {
    int len = 0;
    int i = 0;

    while(input_string[i] != 0) {
        ++i;
        ++len;
    }
    len = len - 1;

    return len - 1;
}


void reverse_string(char input_string[]) {
    
    int beginning = 0;
    
    int length = get_input_length(input_string);
    int end = length;
    while(beginning < end) {
        char temp = input_string[beginning];
        input_string[beginning] = input_string[end];
        input_string[end] = temp;
        ++beginning;
        end--;
    }
    printf("%s", input_string);

}

int main() {
    
    char input_string[100];

    printf("Enter input: ");
    fgets(input_string, sizeof(input_string), stdin);

    reverse_string(input_string);
    return 0;
}