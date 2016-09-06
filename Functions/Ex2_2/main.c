#include <stdio.h>

void my_function(int a) {
  
  a = 7;
  
}

int main() {
  
  int a = 6;

  my_function(a);
  
  printf("The value of a is: %d\n", a);
  
}