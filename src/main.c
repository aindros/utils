#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char** argv)
{
  int i;
  list_item_t *current, *r;
  char buffer[4];
  char *dest = malloc(sizeof(char) * 4);

  iterator_t it;

  list_t list1 = clist_create();
  list_t list2 = clist_create();

  for (i = 0; i < 2; i++) {
    itoa(i, buffer, 10);
    strcpy(dest, "i");
    strcat(dest, buffer);
    clist_add(&list1, dest, sizeof(int));
  }

  for (i = 0; i < 5; i++) {
    itoa(i, buffer, 10);
    strcpy(dest, "j");
    strcat(dest, buffer);
    clist_add(&list2, dest, sizeof(int));
    if (i == 3) r = list2.last;
  }

  clist_remove(&list2, r);
  clist_add_all(&list1, &list2);

  printf("read from list with iterator:\n");
  
  it = clist_iterator(&list1);
  while(iterator_has_next(&it)) {
    current = iterator_next(&it);
    printf("%s\n", (char *) current->data);
  }

  return 0;
}
