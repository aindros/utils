#include <stdlib.h>
#include "list.h"

/*
 * Creates a new list.
 */
List* List_Create(void)
{
  List* list = malloc(sizeof(List));

  list->next    = NULL; /* nwxt element is empty   */
  list->current = list; /* points to itself        */
  list->first   = list; /* first element is itself */
  list->data    = NULL; /* data is empty           */
  list->size    = 0;

  return list;
}

/*
 * Adds a new element to the list.
 */
void List_Add(List* list,  /* list where to add new element */
              void* data,  /* data to add                   */
              int size_of) /* size of the data              */
{
  void* dest = malloc(size_of); /* allocates memory like data parameter */

  memcpy(dest, data, size_of);  /* copies data inside dest              */
  list->data = dest;

  list->next = malloc(sizeof(List));
  list->size ++;
}
