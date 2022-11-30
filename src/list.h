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

#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_item_t {
  void *data;
  struct list_item_t *next;
} list_item_t;

typedef struct list_t {
  struct list_item_t *first;
  struct list_item_t *last;
  int    size;
} list_t;

typedef struct iterator_t {
  struct list_item_t *current;
} iterator_t;

list_t       clist_create           (void);
void         clist_add              (list_t *, void *, int);
void         clist_add_all          (list_t *, list_t *);
void         clist_remove           (list_t *, list_item_t *);
iterator_t   clist_iterator         (list_t *);
int          clist_iterator_has_next(iterator_t *);
list_item_t *clist_iterator_next    (iterator_t *);

#endif
