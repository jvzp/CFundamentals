#include <stdio.h>
#include <stdarg.h>

double sum(int count, ...) {
  
  va_list ap;
  int j;
  double sum = 0;
  
  va_start(ap, count);
  for (j=0; j < count; j++) {
    
      sum += va_arg(ap, double);
      
  }
  va_end(ap);
  
  return (double)sum;
  
}

int main(int argc, char * argv[]) {
  
  fprintf(stdout, "The sum is: %f\n", (sum(5, (double)8, (double)3, (double)7, (double)4, (double)6)));  //casting naar een double want anders gaat de va_arg integers geheugenplaatsen lezen als doubles.. en dit is helaas anders ingedeeld in het geheugen
  return 0;
  
}