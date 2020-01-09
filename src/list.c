#include <stdlib.h>
#include <string.h> /* memcpy */
#include "list.h"

List List_Create()
{
  List list;

  list.first = NULL;
  list.last  = NULL;
  list.size  = 0;

  return list;
}

void List_Add(List*  list,
	      void* data,
	      int   size_of)
{
  struct list_item_t *item = malloc(sizeof(struct list_item_t));

  void *dest = malloc(size_of); /* allocates memory like data parameter */
  memcpy(dest, data, size_of);  /* copies data inside dest              */
  item->data = dest;
  item->next = NULL;

  if (list->first == NULL)
    list->first = item;

  if (list->last != NULL)
    list->last->next = item;

  list->last = item;
  list->size ++;
}

Iterator List_Iterator(List* list)
{
  struct iterator_t *iterator = malloc(sizeof(struct iterator_t));
  iterator->current = list->first;

  return *iterator;
}

int Iterator_HasNext(Iterator* iterator)
{
  return iterator->current != NULL;
}

List_Item *Iterator_Next(Iterator *iterator)
{
  struct list_item_t *current = iterator->current;
  iterator->current = iterator->current->next;

  return current;
}