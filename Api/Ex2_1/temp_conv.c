/******************************************************************
 *								  *
 * Module for temperature conversion				  *
 *								  *
 ******************************************************************/


/*
 * function for the conversion from degrees celsius to Kelvin
 */
double temp_conv_calc_ck(long number) {
  
  double result = number + 273.15;
  return result;
  
}


/*
 * function for the conversion from degrees Fahrenheit to Kelvin
 */
double temp_conv_calc_fk(long number) {
  
  double result = ((number-32)*5/9)+273.15;
  return result;
  
}


/*
 * function for the conversion from degrees celsius to Fahrenheit
 */
double temp_conv_calc_cf(long number) {
  
  double result = ((number*9/5)+32);
  return result;
  
}