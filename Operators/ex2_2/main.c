#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char * argv[] ) {
  
  if(argc < 3) {
    
    printf("Please, fill in enough arguments\n");
    
  } else {
    
    int base = 10;
    
    if(strcmp(argv[argc-1],"0x") == 0) {
      
      base = 16;
      
    } else if(strcmp(argv[argc-1],"o") == 0) {
      
      base = 8;
      
    } else if(strcmp(argv[argc-1],"d") == 0) {
     
      base = 10;
      
    } else {
      
      printf("Please, use the format: ./ProgramName <Operator> [<numbers>] <number format: 0x, o or d>\n");
      
    }
    
    long int strtol(const char *nptr, char **endptr, int base);
    
    int i = 0;
    int result = 0;
    
    if(strcmp(argv[1],"+") == 0) {
      
      for(i = 2; i < argc-1; i++) {
	result += strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"-") == 0) {
      
      for(i = 2; i < argc-1; i++) {
	result -= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"*") == 0) {
      
      result = 1;
      
      for(i = 2; i < argc-1; i++) {
	result *= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"/") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	
	int a = result;
	
	if( (a % atoi(argv[i])) != 0 ) {
	  result %= strtol((argv[i]), NULL, base);
	} else {
	  result /= strtol((argv[i]), NULL, base);
	}
      }
      
    } else if(strcmp(argv[1],"&") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	result &= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"|") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	result |= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"^") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	result ^= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],"~") == 0) {
      
      for(i = 2; i < argc-1; i++) {
	result = ~(strtol((argv[i]), NULL, base));
      }
      
    } else if(strcmp(argv[1],"<<") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	result <<= strtol((argv[i]), NULL, base);
      }
      
    } else if(strcmp(argv[1],">>") == 0) {
      
      result = atoi(argv[2]);
      
      for(i = 3; i < argc-1; i++) {
	result >>= strtol((argv[i]), NULL, base);
      }
      
    } else {
      printf("Unsupported operator\n");
    }
    
    printf("The result is: %d\n", result);
    
  }
  
}