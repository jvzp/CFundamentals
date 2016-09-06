#include <stdio.h>

void * memcpy(void * str1, const void * str2, size_t n) {
  
  int count = 0;
  char * help_1 = (char *)str2;
  char * help_2 = (char *)str1;
  
  for( count = 0 ; count < n ; count++ ) {
    
    *help_2 = *help_1;
    
    help_1++;
    help_2++;
    
  }
  
}

int main() {
  
  char * text = "Hello";
  char text_copied[6] = "aaaaa";
  
  printf("The original text is: %s\n", text);
  
  memcpy(text_copied, text, 6);
  
  printf("The copied text is: %s\n", text_copied);
  
  
}