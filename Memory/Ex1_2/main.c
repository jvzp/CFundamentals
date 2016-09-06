#include <stdlib.h>
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
  
  int * mem = NULL;
  int getal = 0;
  char p[20];
  
  //Getting the amount of data
  printf("Please enter how many numbers you like to add.\n");
  int n = scanf("%s\n", p);
  if (n == 1) {
    
    getal = atoi(p);
    mem = malloc(getal*sizeof(int));
    if( mem == NULL ) {
      
      printf("No free memory available...");
      return 0;
      
    }
      
  } else {
    
      fprintf(stderr, "Something went wrong...\n");
      
  }
  
  int count = 0;
  
  //Getting the actual data
  for( count = 0 ; count < getal ; count++ ) {
    
    printf("please enter a number!\n");
    
    int a = scanf("%s\n", p);
    if (a == 1) {
      
      int number = atoi(p);
      *mem = number;
      mem++;
	
    } else {
	fprintf(stderr, "Something went wrong...\n");
    }
    
  }
  
  for( count = 0 ; count < getal ; count++ ) {
    
    mem--;
    
  }
  
  memdump(mem, (getal*sizeof(int)));
  
}