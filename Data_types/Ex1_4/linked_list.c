/****************************************************************************
 *									    *
 * Source file for the Linked List					    *
 *									    *
 * Author: Jonas Vanzurpele						    *
 *									    *
 ****************************************************************************/

#include "linked_list.h"

typedef struct node {
  
  node * previous;
  node * next;
  int value;
  
} node;


/*
 * Method for adding elements to the list, the list should be a NULL if a new list is to be created.
 */
node * linked_list_insert_after(node * list, int element) {
  
  if (list == NULL) {
    
    node * start_node = malloc(sizeof(node));
    if (start_node == NULL) {
      
      fprintf(stderr, "Could not allocate memory for the linked list.");
      exit(EXIT_FAILURE);
      
    }
    start_node->previous = NULL;
    start_node->next = NULL;
    start_node->value = element;
    return start_node;
    
  } else {
    
    node * previous_node = list->previous;
    node * previous_current = list;
    node * next_node = list->next;
    while(next_node != NULL) {
      
      previous_node = next_node->previous;
      previous_current = next_node;
      next_node = next_node->next;
      
    }
    
    next_node = malloc(sizeof(node));
    node * current = next_node;
    
    previous_current->next = next_node;
    current->previous = previous_node;
    current->next = NULL;
    current->value = element;
    
    return list;
    
  }
  
}


/*
 * Method for freeing all of the allocated memory
 */
int linked_list_free(node * list) {
  
  node * next_to_be_freed = list->next;
  free(list);
  list = NULL;
  
  while (next_to_be_freed != NULL) {
    
    node * helper = next_to_be_freed;
    next_to_be_freed = next_to_be_freed->next;
    free(helper);
    helper = NULL;
    
  }
  
  return 0;
  
}


/*
 * Method for printing the entire list.
 */
node * linked_list_print(node * list) {
  
  node * helper = list;
  int count = 0;
  
  while ( (helper->next) != NULL ) {
    
    printf("The element at index %d is: %d\n", count, helper->value);
    count++;
    helper = helper->next;
    
  }
  
  printf("The element at index %d is: %d\n", count, helper->value);
  
  return list;
  
}


/*
 * Returns the number of elements in the list
 */
int linked_list_count(node * list) {
  
  node * helper = list;
  int count = 1;
  
  while ( (helper->next) != NULL ) {
    
    count++;
    helper = helper->next;
    
  }
  
  return count;
  
}


/*
 * Main function, mainly for testing purposes
 * 
 * ToDo: making a module of the linked list, for making it possible to use it anywhere else.
 */
int main() {
  
  node * list = linked_list_insert_after(NULL, 4);
  list = linked_list_insert_after(list, 32);
  list = linked_list_insert_after(list, 5);
  list = linked_list_insert_after(list, 7);
  
  list = linked_list_print(list);
  
  printf("So, the amount of numbers in the list is: %d\n", linked_list_count(list));
  
  linked_list_free(list);
  
  return 0;
  
}