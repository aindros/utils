/*
 * Copyright (C) 2022  Alessandro Iezzi <aiezzi AT alessandroiezzi PERIOD it>
 *
 * This file is part of clist.
 *
 * clist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * clist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with clist.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h> /* memcpy */
#include "list.h"

list_t clist_create()
{
  list_t list;

  list.first = NULL;
  list.last  = NULL;
  list.size  = 0;

  return list;
}

void clist_add(list_t *list,
               void   *data,
               int     size_of)
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

void clist_add_all(list_t *dest,
                   list_t *other)
{
  dest->last->next = other->first;
  dest->size += other->size;
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

iterator_t clist_iterator(list_t *list)
{
  struct iterator_t *iterator = malloc(sizeof(struct iterator_t));
  iterator->current = list->first;

  return *iterator;
}

int iterator_has_next(iterator_t *iterator)
{
  return iterator->current != NULL;
}

list_item_t *iterator_next(iterator_t *iterator)
{
  struct list_item_t *current = iterator->current;
  iterator->current = iterator->current->next;

  return current;
}
