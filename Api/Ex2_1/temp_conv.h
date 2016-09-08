#ifndef _TEMP_CONV_H_
#define _TEMP_CONV_H_

/******************************************************************
 *								  *
 * Module for temperature conversion				  *
 *								  *
 ******************************************************************/


/*
 * function for the conversion from degrees celsius to Kelvin
 */
double temp_conv_calc_ck(long number);


/*
 * function for the conversion from degrees Fahrenheit to Kelvin
 */
double temp_conv_calc_fk(long number);


/*
 * function for the conversion from degrees celsius to Fahrenheit
 */
double temp_conv_calc_cf(long number);

#endif