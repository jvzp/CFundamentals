#include <stdio.h>
#include <stdlib.h>

#define SWAP(t, x, y) do {	\
  t = x;			\
  x = y;			\
  y = t;			\
} while(0)

int main(int argc, char * argv[]) {
  
  if(argc < 3) {
    
    fprintf(stderr, "Please also enter 2 numbers to swap\n");
    exit(EXIT_FAILURE);
    
  } else {
    
    int t = 0;
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    
    SWAP(t,x,y);
    
    fprintf(stdout, "The numbers swapped: %d and %d\n", x, y);
    
  }
  
  return 0;
  
}