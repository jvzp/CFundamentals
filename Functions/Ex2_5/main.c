#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

double calc_ck(long number) {
  
  double result = number + 273.15;
  return result;
  
}

double calc_fk(long number) {
  
  double result = ((number-32)*5/9)+273.15;
  return result;
  
}

double calc_cf(long number) {
  
  double result = ((number*9/5)+32);
  return result;
  
}

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
      
      printf("The temperature in Kelvin is: %f\n", calc_ck(res_help));
      
    }
    
  } else if ( strcmp(argv[1],"f2k") == 0 ) {
    
    char * end;
    int res_help = strtol(argv[2], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The temperature in Kelvin is: %f\n", calc_fk(res_help));
      
    }
    
  } else if ( strcmp(argv[1],"c2f") == 0 ) {
    
    char * end;
    int res_help = strtol(argv[2], &end, 10);

    if (*end) {
      
      printf("Conversion error, non-convertible part: %s\n", end);
      
    } else {
      
      printf("The temperature in Fahrenheit is: %f\n", calc_cf(res_help));
      
    }
    
  }
  
}