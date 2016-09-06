#include <stdio.h>

int main() {
  
  int a = 5;
  double b = 7.3;
  
  int * pointer_to_a = &a;
  double * pointer_to_b = &b;
  
  printf("The addres of a is: %p\n", pointer_to_a);
  printf("The addres of b is: %p\n", pointer_to_b);
  
  printf("The value of a is: %d\n", *pointer_to_a);
  printf("The value of b is: %f\n", *pointer_to_b);
  
  *pointer_to_a = 3;
  *pointer_to_b = 4.5;
  
  printf("The value of a is: %d\n", *pointer_to_a);
  printf("The value of b is: %f\n", *pointer_to_b);
  
}