#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = (List*)malloc(sizeof(List)); /* allocating memory for the list */
  list->root = NULL; /* setting root node to NULL */
  
  return list;
}

void add_history(List *list, char *str)
{
  Item *curr = list->root; /* pointer variable to root */

  Item *newItem = (Item*)malloc(sizeof(Item)); /* allocating memory for the new item */
  newItem->str = copy_str(str,string_length(str)); /* copying new item */
  newItem->next = NULL; /* sets next node to NULL */

  if(curr == NULL){ /* checking if current node is NULL */
    newItem->id = 0; /* new item is set to index zero */
    list->root = newItem; /* new item is set to root */
    return;
  }
  else{
    while(curr->next){ /* loop through list */
      curr = curr->next;
    }
    newItem->id = curr->id + 1; /* sets new item to end of list*/
    curr->next = newItem;
  }
}

char *get_history(List *list, int id)
{
  Item *curr = list->root; /* current node pointer set to root */
  if(curr == NULL) return NULL; /* checking if current node is NULL */
  while(curr && curr->id != id){ /* traversing through list until Item->id == id */
    curr = curr->next;
  }
  return curr->str; /* returns string of node at id */
}

void print_history(List *list)
{
  Item *curr = list->root; /* pointer set to root */

  while(curr != NULL){ /* traversing through the list */
    printf("Id = %d\t%s\n", curr->id, curr->str); /* printing out the contents of the list */
    curr = curr->next;
  }
}

void free_history(List *list)
{
  Item *curr = list->root; /* pointer set to root */
  Item *tmp; /* initialization of temp variable */

  while(curr != NULL){ /* traversing through list */
    tmp = curr->next; /* temp variable points to next node */
    free(curr); /* current node is freed */
    curr = tmp; /* current node is set to temp */
  }
  free(list->root); /* freeing the root node */
  list->root = NULL; /* setting the root to NULL */
}
