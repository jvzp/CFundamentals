#include <stdio.h>
#include <stdlib.h>

int sum_recursive(int n) {
  
  if(n!=0) {
    
      return n+sum_recursive(n-1);
      
  }
  else {
    
      return n;
      
  }
  
}

int main(int argc, char * argv[]) {
  
  if(argv[1] == NULL) {
    
    fprintf(stderr, "Please enter a number.\n");
    exit(EXIT_FAILURE);
    
  } else {
    
    char * end;
    int res_help = strtol(argv[1], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The sum is: %d\n", sum_recursive(res_help));
      
    }
    
  }
  
}