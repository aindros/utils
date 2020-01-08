#include <stdio.h>
#include "list.h"

int main(int argc, char** argv)
{
  int test1 = 5;
  int test2 = 32;

  List* list = List_Create();

  List_Add(list, &test1, sizeof(int));
  List_Add(list, &test2, sizeof(int));

  int* t = list->data;

  printf("Valore: %i, size: %i\n", *t, list->size);

  return 0;
}
