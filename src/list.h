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
list_item_t *iterator_next          (iterator_t *);

#endif
