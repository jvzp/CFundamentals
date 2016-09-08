#include <stdio.h>
#include <stdlib.h>

typedef struct relative_time {
  
  int days;
  int hours;
  int minutes;
  int seconds;
  
} relative_time;

/*
 * Create an instance of relative time
 */
relative_time * relative_time_create(int day, int hours, int minutes, int seconds) {
  
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
int relative_time_check_invariant(int day, int hours, int minutes, int seconds) {
  
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

int relative_time_check_invariant_instance(relative_time * const instance) {
  
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
  
  check_invariant(time_1->days, time_1->hours, time_1->minutes, time_1->seconds);
  check_invariant(time_2->days, time_2->hours, time_2->minutes, time_2->seconds);
  
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
relative_time * relative_time_add(relative_time * const time_1, relative_time * const time_2, relative_time * const result) {
  
  check_invariant(time_1->days, time_1->hours, time_1->minutes, time_1->seconds);
  check_invariant(time_2->days, time_2->hours, time_2->minutes, time_2->seconds);
  result->seconds = time_1->seconds + time_2->seconds;
  result->minutes = time_1->minutes + time_2->minutes;
  result->hours = time_1->hours + time_2->hours;
  result->days = time_1->days + time_2->days;
  check_invariant_instance(result);
  
}

void relative_time_print(relative_time * time) {
  
  check_invariant(time->days, time->hours, time->minutes, time->seconds);
  fprintf(stdout, "{ days: %d; hours: %d; minutes: %d; seconds: %d }\n", time->days, time->hours, time->minutes, time->seconds);
  
}

/*
 * Main function
 */
int main() {
  
  relative_time * time_1 = create_relative_time(18,0,4,0);
  relative_time * time_2 = create_relative_time(0,4,0,59);
  relative_time * time_3 = create_relative_time(0,0,0,0);
  
  printf("The outcome of the comparison function was: %d\n", relative_time_cmp(time_1, time_2));
  
  add(time_1,time_2,time_3);
  
  relative_time_print(time_3);
  
  free(time_1);
  free(time_2);
  free(time_3);
  
}