#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "temp_conv.h"

int main( int argc, char * argv[] ) {
  
  if(argv[2] == NULL) {
    
    fprintf(stderr, "Please enter a temperature to convert.\n");
    exit(EXIT_FAILURE);
    
  } else if( strcmp(argv[1],"c2k") == 0 ) {
    
    char * end;
    int res_help = strtol(argv[2], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The temperature in Kelvin is: %f\n", temp_conv_calc_ck(res_help));
      
    }
    
  } else if ( strcmp(argv[1],"f2k") == 0 ) {
    
    char * end;
    int res_help = strtol(argv[2], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The temperature in Kelvin is: %f\n", temp_conv_calc_fk(res_help));
      
    }
    
  } else if ( strcmp(argv[1],"c2f") == 0 ) {
    
    char * end;
    int res_help = strtol(argv[2], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The temperature in Fahrenheit is: %f\n", temp_conv_calc_cf(res_help));
      
    }
    
  }
  
}