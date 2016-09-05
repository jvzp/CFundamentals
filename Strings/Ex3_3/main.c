#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
  
  int i = 0;
  int j = 0;
  
  for(j = 0; j < argc; j++) {
    
    char * string = argv[j];
  
    printf("%s \t\t", string);
    
    for(i = 0; i < strlen(string); i++) {
      
      string[i] -= 32;
      
    }
    
    printf("=> %s\n", string);
    
  }
  
}