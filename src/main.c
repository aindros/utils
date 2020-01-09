#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char** argv)
{
  int i;
  int *t;
  List_Item *current;
  char buffer[4];
  char *dest = malloc(sizeof(char) * 4);

  Iterator it;

  List list = List_Create();

  for (i = 0; i < 23; i++) {
    itoa(i, buffer, 10);
    strcpy(dest, "i");
    strcat(dest, buffer);
    List_Add(&list, dest, sizeof(int));
  }

  printf("read from list with iterator:\n");
  
  it = List_Iterator(&list);
  while(Iterator_HasNext(&it)) {
    current = Iterator_Next(&it);
    printf("%s\n", (char *) current->data);
  }

  return 0;
}
