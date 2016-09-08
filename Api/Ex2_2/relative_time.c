#include "relative_time.h"

typedef struct relative_time {
  
  int days;
  int hours;
  int minutes;
  int seconds;
  
} relative_time;

/*
 * Create an instance of relative time
 */
relative_time * create_relative_time(int day, int hours, int minutes, int seconds) {
  
  if (check_invariant(day,hours,minutes,seconds) == 1) {
    
    relative_time* new_instance = malloc(sizeof(relative_time));
    if(new_instance == NULL) {
      
      fprintf(stderr, "A time instance could not be printed\n");
      exit(EXIT_FAILURE);
      
    }
    new_instance->days = day;
    new_instance->hours = hours;
    new_instance->minutes = minutes;
    new_instance->seconds = seconds;
    return new_instance;
    
  }
  
}

/*
 * To check the time for correctness
 */
int check_invariant(int day, int hours, int minutes, int seconds) {
  
  if (range(0,24,hours)==0) {
    
    fprintf(stderr, "please enter a valid number for hours\n");
    exit(EXIT_FAILURE);
    
  } else if (range(0,60,minutes)==0) {
    
    fprintf(stderr, "please enter a valid number for minutes\n");
    exit(EXIT_FAILURE);
    
  } else if (range(0,60,seconds)==0) {
    
    fprintf(stderr, "please enter a valid number for seconds\n");
    exit(EXIT_FAILURE);
    
  } else {
    
    return 1;
    
  }
  
}

int check_invariant_instance(relative_time * const instance) {
  
  if((instance->seconds)>=60) {
    
    instance->seconds -= 60;
    (instance->minutes)++;
    
  }
  if((instance->minutes)>=60) {
    
    instance->minutes -= 60;
    (instance->hours)++;
    
  }
  if((instance->hours)>=24) {
    
    instance->hours -= 24;
    (instance->days)++;
    
  }
  
  return 1;  
  
}

/*
 * Used in the check_invariant function
 */
int range(int min, int max, int number) {
  
  if((number<max)&&(number>=min)) {
    
    return 1;
    
  } else {
    
    return 0;
    
  }
  
}

/*
 * compare two relative_time instances
 */
int relative_time_cmp(relative_time * const time_1, relative_time * const time_2) {
  
  if ((time_2->days)>(time_1->days)) {
    
    return 1;
    
  } else if ((time_2->days)<(time_1->days)) {
    
    return -1;
    
  } else {
    
    if ((time_2->hours)>(time_1->hours)) {
    
      return 1;
      
    } else if ((time_2->hours)<(time_1->hours)) {
      
      return -1;
      
    } else {
      
      if ((time_2->minutes)>(time_1->minutes)) {
    
	return 1;
	
      } else if ((time_2->minutes)<(time_1->minutes)) {
	
	return -1;
	
      } else {
	
	if ((time_2->seconds)>(time_1->seconds)) {
    
	  return 1;
	  
	} else if ((time_2->seconds)<(time_1->seconds)) {
	  
	  return -1;
	  
	} else {
	  
	  return 0;
	  
	}
	
      }
      
    }
    
  }
  
}

/*
 * Add two time instances and put it in result
 */
relative_time * add(relative_time * const time_1, relative_time * const time_2, relative_time * const result) {
  
  result->seconds = time_1->seconds + time_2->seconds;
  result->minutes = time_1->minutes + time_2->minutes;
  result->hours = time_1->hours + time_2->hours;
  result->days = time_1->days + time_2->days;
  check_invariant_instance(result);
  
}