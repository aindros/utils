#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_t {
  void*  data;
  struct List* next;
  struct List* first;
  struct List* current;
  int    size;
} List;

List* List_Create(void);
void  List_Add   (List*, void*, int);
void  List_Remove();

#endif
