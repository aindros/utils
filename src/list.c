/* See LICENSE file for copyright and license details. */

#include <stdlib.h>
#include <string.h> /* memcpy */
#include "utils.h"

list_t
clist_create()
{
  list_t list;

  list.first = NULL;
  list.last  = NULL;
  list.size  = 0;

  return list;
}

void
clist_add(list_t *list,
          void   *data,
          size_t  data_s)
{
	struct list_item_t *item = malloc(sizeof(struct list_item_t));

	void *dest = malloc(data_s); /* allocates memory like data parameter */
	memcpy(dest, data, data_s);  /* copies data inside dest              */
	item->data = dest;
	item->data_s = data_s;
	item->next = NULL;

  if (list->first == NULL)
    list->first = item;

  if (list->last != NULL)
    list->last->next = item;

  list->last = item;
  list->size ++;
}

void clist_add_all(list_t *dest,
                   list_t *other)
{
	/* Concatenation of both lists must be iterated and not referenced becasue
	 * if you clear `other` you'll lost all elements */

	iterator_t i = clist_iterator(other);
	while (clist_iterator_has_next(i)) {
		list_item_t *item = clist_iterator_next_item(&i);
		clist_add(dest, item->data, item->data_s);
	}
}

void clist_remove(list_t *list,
                  list_item_t *item)
{
  list_item_t *curr = list->first->next;
  list_item_t *prev = list->first;

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

iterator_t
clist_iterator(list_t *list)
{
  struct iterator_t *iterator = malloc(sizeof(struct iterator_t));
  iterator->current = list->first;

  return *iterator;
}

int
clist_iterator_has_next(iterator_t i)
{
	return i.current != NULL;
}

void *
clist_iterator_next(iterator_t *i)
{
	if (i == NULL || i->current == NULL)
		return NULL;

	void *data = i->current->data;
	/* `next` can be NULL */
	i->current = i->current->next;

	return data;
}

list_item_t *
clist_iterator_next_item(iterator_t *i)
{
	if (i == NULL || i->current == NULL)
		return NULL;

	list_item_t *item = i->current;
	/* `next` can be NULL */
	i->current = i->current->next;

	return item;
}
