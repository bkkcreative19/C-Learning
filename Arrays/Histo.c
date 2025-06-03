#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE = 9



void print_histo(int num) {
  for (int i = 0; i < num; i++) {
    putchar('#');
  }
}

int main() {

  char c;
  int options[10];
  FILE *fptr = fopen("yay.txt", "r");

  int count = 0;

  for (int i = 0; i < 10; i++) {
    options[i] = 0;
  }

  while ((c = fgetc(fptr)) != EOF) {
    if(c == '\n' || c == '\t' || c == ' ' || c == EOF) {
      ++options[count];
      count = 0;
      continue;
    }

    count++;
    // printf("%d\n", count);
    // printf("%c", ch);
  }


  printf("Horizontal Histogram\n");

  for (int i = 0; i < 20; i++) {
    printf("_");
  }

  puts("\n");
  
  for (int i = 0; i < 10; i++) {
    printf("   %d:    ", i);
    print_histo(options[i]);
    puts("\n");
  }
  

  fclose(fptr);
  return 0;
}