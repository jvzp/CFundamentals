#include <stdio.h>
#include <stdlib.h>

int a = 0;

int check_bounderies(int number, int max, int min) {
  
  if((number <= max) && (number >= min)) {
    
    return 1;
    
  } else {
    
    return 0;
    
  }
  
}

int add_hours(int number_1, int number_2) {
  
  int hour = 0;
  
  if(check_bounderies(number_1, 23, 0) && check_bounderies(number_2, 23, 0)) {
    
    hour = number_1 + number_2;
    if(check_bounderies(hour,23,0)) {
      
      return hour;
      
    } else {
      
      return hour-24;
      
    }
    
  } else {
    
    fprintf(stderr, "Please enter valid hours.\n");
    exit(EXIT_FAILURE);
    
  }
  
}

int add_minutes(int number_1, int number_2, int * hours) {
  
  int minute = 0;
  
  if(check_bounderies(number_1, 59, 0) && check_bounderies(number_2, 59, 0)) {
    
    minute = number_1 + number_2;
    if(check_bounderies(minute,59,0)) {
      
      return minute;
      
    } else {
      
      (*hours)++;
      return minute-60;
      
    }
    
  } else {
    
    fprintf(stderr, "Please enter valid minutes.\n");
    exit(EXIT_FAILURE);
    
  }
  
}

int main( int argc, char * argv[] ) {
  
  int hour_1 = atoi(argv[1]);
  int min_1 = atoi(argv[2]);
  int hour_2 = atoi(argv[3]);
  int min_2 = atoi(argv[4]);
  
  int hours = add_hours(hour_1, hour_2);
  int minutes = add_minutes(min_1, min_2, &hours);
  
  printf("The time is: %d hours and %d minutes\n", hours, minutes);
  
}