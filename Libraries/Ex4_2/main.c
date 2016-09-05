#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int max = 0;  
  char p[20];
  int count = 10;
  
  printf("Please enter 10 numbers!\n");
  
  while(count != 0) {
    
    int n = scanf("%s\n", p);
    if (n == 1) {
      
	int getal = atoi(p);
	
	if( getal > max ) {
	  
	  max = getal;
	  
	}
	
    } else {
	fprintf(stderr, "Something went wrong...\n");
    }
    
    count--;
    
  }
  
  printf("The maximum of this series of numbers is: %d\n", max);

  
}