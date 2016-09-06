#include <stdio.h>

double calc_ck(int number) {
  
  double result = number + 273.15;
  return result;
  
}

double calc_fk(int number) {
  
  double result = ((number-32)*5/9)+273.15;
  return result;
  
}

double calc_cf(int number) {
  
  double result = ((number*9/5)+32);
  return result;
  
}

double calc_kc(int number) {
  
  return number;
  
}
double calc_kf(int number) {
  
  return number;
  
}
double calc_fc(int number) {
  
  return number;
  
}

int main( int argc, char * argv[] ) {
  
  if( strcmp(argv[1],"c2k") == 0 ) {
    
    printf("The temperature in Kelvin is: %f\n", calc_ck(atoi(argv[2])));
    
  } else if ( strcmp(argv[1],"f2k") == 0 ) {
    
    printf("The temperature in Kelvin is: %f\n", calc_fk((int)atoi(argv[2])));
    
  } else if ( strcmp(argv[1],"c2f") == 0 ) {
    
    printf("The temperature in Fahrenheit is: %f\n", calc_cf((int)atoi(argv[2])));
    
  } /*else if( strcmp(argv[1],"k2c") == 0 ) {
    
    printf("The temperature in Celsius is: %e\n", calc_kc((int)atoi(argv[2])));
    
  } else if ( strcmp(argv[1],"k2f") == 0 ) {
    
    printf("The temperature in Fahrenheit is: %e\n", calc_kf((int)atoi(argv[2])));
    
  } else if ( strcmp(argv[1],"f2c") == 0 ) {
    
    printf("The temperature in Celsius is: %e\n", calc_fc((int)atoi(argv[2])));
    
  } */
  
}