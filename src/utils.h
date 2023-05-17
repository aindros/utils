/* See LICENSE file for copyright and license details. */

#ifndef __CUTILS_H__
#define __CUTILS_H__

typedef struct list_item_t {
  void *data;
  size_t data_s;
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
void         clist_add              (list_t *, void *);
void         clist_add_s            (list_t *, void *, size_t);
void         clist_add_all          (list_t *, list_t *);
void         clist_remove           (list_t *, list_item_t *);
iterator_t   clist_iterator         (list_t *);
int          clist_iterator_has_next(iterator_t);
void        *clist_iterator_next    (iterator_t *);
list_item_t *clist_iterator_next_item(iterator_t *);

char *cutils_version();

#endif /* __CUTILS_H__ */
