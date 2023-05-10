/*
 * Copyright (C) 2022-2023  Alessandro Iezzi <aiezzi AT alessandroiezzi PERIOD it>
 *
 * This file is part of libutils.
 *
 * libutils is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libutils is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libutils. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#define assert(c) if (c == 0) { printf("%d", __LINE__); exit(1);}
#define log(str) printf("%s: %s\n", __func__, str);

void
test_list1()
{
	/* Test adding elements in a list */
	log("Running...");

	const char *data = "hello";

	list_t list = clist_create();
	clist_add(&list, (void *) data, strlen(data) + 1);

	assert(list.first == list.last);
	assert(strcmp(list.first->data, data) == 0);
	assert(list.size == 1);

	log("OK\n");
}

void
test_list2()
{
	/* Test iterator */
	log("Running...");

	char *data1 = strdup("hello");

	list_t list = clist_create();
	clist_add(&list, data1, strlen(data1) + 1);

	iterator_t it = clist_iterator(&list);
	assert(clist_iterator_has_next(it));

	void *data2 = clist_iterator_next(&it);
	assert(data2 != NULL);
	assert(strcmp(data1, data2) == 0);

	assert(clist_iterator_has_next(it) == 0);

	log("OK\n");
}

void
test_list3()
{
	/* Test adding a collection to another one */
	log("Running...");

	list_t l1 = clist_create();
	list_t l2 = clist_create();

	char *str1 = "test1";
	char *str2 = "test2";

	clist_add(&l1, str1, strlen(str1) + 1);
	clist_add(&l2, str2, strlen(str2) + 1);

	clist_add_all(&l1, &l2);

	iterator_t i = clist_iterator(&l1);
	if (clist_iterator_has_next(i))
		assert(strcmp(clist_iterator_next(&i), "test1") == 0);

	if (clist_iterator_has_next(i))
		assert(strcmp(clist_iterator_next(&i), "test2") == 0);

	assert(l1.size == 2);

	log("OK\n");
}

void
test_list4()
{
	/* Test adding a collection to another one and add a new element */
	log("Running...");

	list_t l1 = clist_create();
	list_t l2 = clist_create();

	char *s1 = "test1";
	char *s2 = "test2";
	char *s3 = "test3";

	clist_add(&l1, s1, strlen(s1) + 1);
	clist_add(&l2, s2, strlen(s2) + 1);
	clist_add_all(&l1, &l2);

	/* add a new element */
	clist_add(&l1, s3, strlen(s3) + 1);

	iterator_t i = clist_iterator(&l1);
	if (clist_iterator_has_next(i))
		assert(strcmp(clist_iterator_next(&i), "test1") == 0);

	if (clist_iterator_has_next(i))
		assert(strcmp(clist_iterator_next(&i), "test2") == 0);

	if (clist_iterator_has_next(i))
		assert(strcmp(clist_iterator_next(&i), "test3") == 0);

	log("OK\n");
}

void
test_list5()
{
	log("Running...");


list_item_t *r;
  char buffer[4];
  char *dest = malloc(sizeof(char) * 4);

  iterator_t it;

  list_t list1 = clist_create();
  list_t list2 = clist_create();

  for (int i = 0; i < 2; i++) {
    sprintf(buffer, "%d", i);
    strcpy(dest, "i");
    strcat(dest, buffer);
    clist_add(&list1, dest, strlen(dest) + 1);
  }

  for (int i = 0; i < 5; i++) {
    sprintf(buffer, "%d", i);
    strcpy(dest, "j");
    strcat(dest, buffer);
    clist_add(&list2, dest, strlen(dest) + 1);
    if (i == 3) r = list2.last;
  }

  clist_remove(&list2, r);
  clist_add_all(&list1, &list2);


  printf("read from list with iterator:\n");

  it = clist_iterator(&list1);
  while(clist_iterator_has_next(it)) {
    printf("%s\n", (char *) clist_iterator_next(&it));
  }

  printf("%s\n", (char *) list1.first->data);
	log("OK\n");
}

void
test_list6()
{
	log("Running...");

	char buff[127];
	sprintf(buff, "Version: %s", cutils_version());
	log(buff);

	log("OK\n");
}

void
test_list7()
{
	/* Test adding long strings to the list */
	log("Running...");

	list_t list1 = clist_create();

	char *str1 = "Long string 1";
	char *str2 = "Long string 2";
	char *str3 = "Long string 3";
	char *str4 = "";
	char *str5 = "Long string 4";

	clist_add(&list1, strdup(str1), strlen(str1) + 1);
	clist_add(&list1, strdup(str2), strlen(str2) + 1);
	clist_add(&list1, strdup(str3), strlen(str3) + 1);
	clist_add(&list1, strdup(str4), strlen(str4) + 1);
	clist_add(&list1, strdup(str5), strlen(str5) + 1);

	iterator_t it = clist_iterator(&list1);

	assert(clist_iterator_has_next(it));
	assert(strcmp((char *) clist_iterator_next(&it), "Long string 1") == 0);

	assert(clist_iterator_has_next(it));
	assert(strcmp((char *) clist_iterator_next(&it), "Long string 2") == 0);

	assert(clist_iterator_has_next(it));
	assert(strcmp((char *) clist_iterator_next(&it), "Long string 3") == 0);

	assert(clist_iterator_has_next(it));
	assert(strcmp((char *) clist_iterator_next(&it), "") == 0);

	assert(clist_iterator_has_next(it));
	assert(strcmp((char *) clist_iterator_next(&it), "Long string 4") == 0);

	assert(clist_iterator_has_next(it) == 0);

	log("OK\n");
}

void
test_list8()
{
	log("Running...");

	struct test_struct {
		char *data;
	};

	struct test_struct *s1 = malloc(sizeof(struct test_struct *));
	struct test_struct *s2 = malloc(sizeof(struct test_struct *));

	s1->data = strdup("A long, but very long long string");
	s2->data = strdup("Lorem ipsum");

	list_t l = clist_create();

	clist_add(&l, s1, sizeof(s1));
	clist_add(&l, s2, sizeof(s2));

	iterator_t it = clist_iterator(&l);

	assert(clist_iterator_has_next(it));
	assert(strcmp(((struct test_struct *) clist_iterator_next(&it))->data, "A long, but very long long string") == 0);

	assert(clist_iterator_has_next(it));
	assert(strcmp(((struct test_struct *) clist_iterator_next(&it))->data, "Lorem ipsum") == 0);

	assert(clist_iterator_has_next(it) == 0);

	log("OK\n");
}
