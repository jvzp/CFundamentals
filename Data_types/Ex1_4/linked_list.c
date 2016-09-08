#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

typedef struct node {
  
  node * previous;
  node * next;
  int value;
  
} node;

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
    node * next_node = list->next;
    while(next_node != NULL) {
      
      previous_node = next_node;
      next_node = next_node->next;
      
    }
    
    next_node->next = malloc(sizeof(node));
    node * current = next_node->next;
    
    current->previous = previous_node;
    current->next = NULL;
    current->value = element;
    
    return list;
    
  }
  
}

int linked_list_free(node * list) {
  
  node * next_node = list->next;
  free(list);
  
  while ( next_node != NULL ) {
    
    next_node = next_node->next;
    free(next_node->previous);
    
  }
  
  node * helper = next_node->previous;
  node * last = helper->next;
  
  free(helper);
  free(last);
  
}

int main() {
  
  node * list = linked_list_insert_after(NULL, 4);
  list = linked_list_insert_after(list, 6);
  list = linked_list_insert_after(list, 9);
  linked_list_free(list);
  
}