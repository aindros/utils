#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char** argv)
{
  int i;
  List_Item *current, *r;
  char buffer[4];
  char *dest = malloc(sizeof(char) * 4);

  Iterator it;

  List list1 = List_Create();
  List list2 = List_Create();

  for (i = 0; i < 2; i++) {
    itoa(i, buffer, 10);
    strcpy(dest, "i");
    strcat(dest, buffer);
    List_Add(&list1, dest, sizeof(int));
  }

  for (i = 0; i < 5; i++) {
    itoa(i, buffer, 10);
    strcpy(dest, "j");
    strcat(dest, buffer);
    List_Add(&list2, dest, sizeof(int));
    if (i == 3) r = list2.last;
  }

  List_Remove(&list2, r);
  List_AddAll(&list1, &list2);

  printf("read from list with iterator:\n");
  
  it = List_Iterator(&list1);
  while(Iterator_HasNext(&it)) {
    current = Iterator_Next(&it);
    printf("%s\n", (char *) current->data);
  }

  return 0;
}
