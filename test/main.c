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
  while(clist_iterator_has_next(&it)) {
    current = iterator_next(&it);
    printf("%s\n", (char *) current->data);
  }

  return 0;
}
