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

void List_AddAll(List *dest, List *other)
{
  dest->last->next = other->first;
  dest->size += other->size;
}

void List_Remove(List *list, List_Item *item)
{
  List_Item *curr = list->first->next;
  List_Item *prev = list->first;

  if (list->first == item) {
    free(list->first);
    list->first = curr;
  } else {
    while (curr != NULL) {
      if (curr == item) {
	prev->next = curr->next;
	free(curr);
	return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
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
