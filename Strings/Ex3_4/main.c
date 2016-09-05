#include <stdio.h>
#include <stdlib.h>

int power( int number, int pow) {
  
  int value = 1;
  int count = pow;
  
  while( count != 0 ) {
    
    value *= number;
    count--;
    
  }
  
  return value;
  
}

int main(int argc, char * argv[]) {
  
  int originalNumber = atoi(argv[1]);
  int number = originalNumber;
  int result = 0;
  int n = 0;
  
  while (originalNumber != 0) {
    
    originalNumber /= 10;
    n++;
    
  }

  originalNumber = number;

  while (originalNumber != 0) {
    
    int remainder = originalNumber%10;
    result += power(remainder, n);
    originalNumber /= 10;
    
  }


  if(result == number) {
    
      printf("%d is an Armstrong number\n",number);
  
  } else {
    
      printf("%d is not an Armstrong number\n",number);
      
  }
  
}