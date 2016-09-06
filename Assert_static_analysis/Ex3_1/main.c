#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void * safe_malloc(size_t size);

int main() {
  
  int * test = safe_malloc(200000000000000*sizeof(int));
  
  printf("Address is: %p\n", test);
  
  free(test);
  
  return 0;
  
}

void * safe_malloc(size_t size) {
  
  void * pointer = malloc(size);
  assert(pointer != NULL);
  
  return pointer;
  
}