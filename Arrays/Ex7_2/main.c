#include <stdio.h>
#include <string.h>

void some_function(char * arr) {
  
  printf("sizeof(a) when passed to another function = %li\n", sizeof(arr));
  
}

int main() {
  
  char a[] = "String literal";
  
  printf("sizeof(a) in main function = %li\n", sizeof(a));
  some_function(a);
  
}