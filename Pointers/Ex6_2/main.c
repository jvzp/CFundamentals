#include <stdio.h>

int main() {
  
  int array_1[] = {1,2,3,4,5};
  char array_2[] = {'a','b','c','d','e'};
  
  int * pointer_to_int = array_1;
  char * pointer_to_char = array_2;
  
  int * help = pointer_to_int;
  char * help_1 = pointer_to_char;
  
  help += 3;
  printf("The value at array_1[3] is: %d\n", *help);
  help_1 += 2;
  printf("The value at array_2[2] is: %c\n", *help_1);
  
}