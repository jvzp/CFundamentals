#include <stdlib.h>
#include <stdio.h>

void * safe_malloc(size_t size);

int main() {
  
  int * test = safe_malloc(200000000000000*sizeof(int));
  
  printf("Address is: %p\n", test);
  
  free(test);
  
  return 0;
  
}

void * safe_malloc(size_t size) {
  
  void * pointer = malloc(size);
  if(pointer == NULL) {
    
    fputs("Allocation could not be done...\n",stderr);
    exit(EXIT_FAILURE);
    exit(0);
    
  }
  
  return pointer;
  
}