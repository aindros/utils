#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_item_t {
  void *data;
  struct list_item_t *next;
} List_Item;

typedef struct list_t {
  struct list_item_t *first;
  struct list_item_t *last;
  int    size;
} List;

typedef struct iterator_t {
  struct list_item_t *current;
} Iterator;

List       List_Create     (void);
void       List_Add        (List *, void *, int);
Iterator   List_Iterator   (List *);
int        Iterator_HasNext(Iterator *);
List_Item *Iterator_Next   (Iterator *);

#endif
