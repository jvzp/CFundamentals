#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/****************************************************************************
 *									    *
 * Header file for the Linked List					    *
 *									    *
 * Author: Jonas Vanzurpele						    *
 *									    *
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>


typedef struct node node;


/*
 * Method for adding elements to the list, the list should be a NULL if a 
 * new list is to be created.
 */
node * linked_list_insert_after(node * list, int element);


/*
 * Method for freeing all of the allocated memory
 */
int linked_list_free(node * list);


/*
 * Method for printing the entire list.
 */
node * linked_list_print(node * list);


#endif