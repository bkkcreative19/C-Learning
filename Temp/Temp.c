#include <stdio.h>              


main() {
    int celsius;
    int fahrenheit;
    int lower = 0;
    int upper = 500;
    int step = 1;

    fahrenheit = lower;

    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit-32) / 9;
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}




