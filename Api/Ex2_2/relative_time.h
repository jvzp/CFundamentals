#ifndef _RELATIVE_TIME_H_
#define _RELATIVE_TIME_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct relative_time relative_time;

/*
 * Create an instance of relative time
 */
relative_time * create_relative_time(int day, int hours, int minutes, int seconds);

/*
 * To check the time for correctness
 */
int check_invariant(int day, int hours, int minutes, int seconds);

/*
 * method for correcting time instances to the correct format
 */
int check_invariant_instance(relative_time * const instance);

/*
 * Used in the check_invariant function
 */
int range(int min, int max, int number);

/*
 * compare two relative_time instances
 */
int relative_time_cmp(relative_time * const time_1, relative_time * const time_2);

/*
 * Add two time instances and put it in result
 */
relative_time * add(relative_time * const time_1, relative_time * const time_2, relative_time * const result);

#endif