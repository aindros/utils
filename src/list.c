/*
 * Copyright (C) 2022-2023  Alessandro Iezzi <aiezzi AT alessandroiezzi PERIOD it>
 *
 * This file is part of libutils.
 *
 * libutils is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libutils is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libutils. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h> /* memcpy */
#include "list.h"

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
          void   *data)
{
  struct list_item_t *item = malloc(sizeof(struct list_item_t));

	void *dest = malloc(sizeof(data)); /* allocates memory like data parameter */
	memcpy(dest, data, sizeof(data));  /* copies data inside dest              */
	item->data = dest;
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
		clist_add(dest, clist_iterator_next(&i));
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

list_item_t
clist_iterator_next(iterator_t *iterator)
{
  struct list_item_t *current = iterator->current;
  iterator->current = iterator->current->next;

  return current;
}

char *
clist_version(void)
{
  return VERSION;
}
