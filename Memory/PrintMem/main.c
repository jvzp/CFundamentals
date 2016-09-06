#include <stdio.h>

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
  
  memdump("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 128);
  
}