#include "relative_time.h"

/*
 * Main function
 */
int main() {
  
  relative_time * time_1 = create_relative_time(18,0,4,0);
  relative_time * time_2 = create_relative_time(0,4,0,59);
  relative_time * time_3 = create_relative_time(0,0,0,0);
  
  printf("The outcome of the comparison function was: %d\n", relative_time_cmp(time_1, time_2));
  
  add(time_1,time_2,time_3);
  
  
  
  free(time_1);
  free(time_2);
  free(time_3);
  
}