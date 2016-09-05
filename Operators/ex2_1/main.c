#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char * argv[] ) {
  
  if(argc < 4) {
    
    printf("Please, fill in enough arguments\n");
    
  } else if (strlen(argv[1]) != 1) {  
    
    printf("The operator should have the length of 1 character.\n");
    
  } else {
    
    int i = 0;
    int result = 0;
    
    if(strcmp(argv[1],"+") == 0) {
      
      for(i = 2; i < argc; i++) {
	result += atoi(argv[i]);
      }
      
    } else if(strcmp(argv[1],"-") == 0) {
      
      for(i = 2; i < argc; i++) {
	result -= atoi(argv[i]);
      }
      
    } else if(strcmp(argv[1],"*") == 0) {
      
      result = 1;
      
      for(i = 2; i < argc; i++) {
	result = result * atoi(argv[i]);
      }
      
    } else if(strcmp(argv[1],"/") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc; i++) {
	
	int a = result;
	
	if( (a % atoi(argv[i])) != 0 ) {
	  result = result % atoi(argv[i]);
	} else {
	  result = result / atoi(argv[i]);
	}
      }
      
      printf("The result is: %d\n", result);
      
    } else {
      printf("Unsupported operator\n");
    }
    
  }
  
}