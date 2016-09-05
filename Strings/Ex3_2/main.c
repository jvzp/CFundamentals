#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
  
  int i = 0;
  for(i = 0; i < argc; i++) {
    
    printf("%s has length: %d\n", argv[i], (int)strlen(argv[i]));
    
  }
  
}