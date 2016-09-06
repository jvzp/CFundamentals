#include <stdio.h>
#include <stdlib.h>

void memdump(void * const ptr, int amount_of_bytes) {
  
  int count = 0;
  int teller = 0;
  int amount = 0;
  int rest = 0;
  char * pointer = ptr;
  
  if((amount_of_bytes%16)==0) {
    
    amount = amount_of_bytes/16;
    
  } else {
    
    amount = (amount_of_bytes/16);
    rest = amount_of_bytes%16;
    
  }
  
  for( teller = 0 ; teller < amount ; teller++ ) {
    
    for( count = 0 ; count < 16 ; count++ ) {
      
      printf("%02X ", *pointer);
      pointer++;
      
    }
    
    printf("\t");
    
    for( count = 0 ; count < 16 ; count++ ) {
      
      pointer--;
      
    }
    
    for( count = 0 ; count < 16 ; count++ ) {
      
      printf("%c ", *pointer);
      pointer++;
      
    }
    
    printf("\n");
    
  }
  
  for( count = 0 ; count < rest ; count++ ) {
    
    printf("%02X ", *pointer);
    pointer++;
    
  }
  
  for( count = 0 ; count < 16-rest ; count++ ) {
    
    printf("   ");
    
  }
  
  printf("\t");
  
  for( count = 0 ; count < rest ; count++ ) {
    
    pointer--;
    
  }
  
  for( count = 0 ; count < rest ; count++ ) {
    
    printf("%c ", *pointer);
    pointer++;
    
  }
  
  printf("\n");
    
}

int main() {
  
  int * mem_1 = malloc(sizeof(int)*8);
  if(mem_1 == NULL) {
    
    return 0;
    
  }
  
  char * mem_2 = malloc(sizeof(char)*17);
  if(mem_2 == NULL) {
    
    return 0;
    
  }
  
  //For the first memory
  printf("Address: %p\n", mem_1);
  
  printf("\n\n");
  
  *mem_1 = 61;
  
  memdump(mem_1,8*sizeof(int));
  
  //For the second memory
  printf("Address: %p\n", mem_2);
  
  printf("\n\n");
  
  *mem_2 = 0x61;
  
  memdump(mem_2,17*sizeof(char));
  
  //free both allocated memories
  free(mem_1);
  mem_1 = NULL;
  free(mem_2);
  mem_2 = NULL;
  
}