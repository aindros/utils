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
#include <list.h>
#include <map.h>

void test_list1();
void test_list2();
void test_list3();
void test_list4();
void test_list5();
void test_list6();

void
test_map()
{
	map_t map = cmap_create();
	cmap_put(&map, "hi",    "test");
	cmap_put(&map, "hello", "test");
	cmap_put(&map, "good",  "test");
	cmap_put(&map, "best",  "test");
}

int main(int argc, char** argv)
{
	test_list1();
	test_list2();
	test_list3();
	test_list4();
	test_list5();
	test_list6();

  test_map();

	return 0;
}
