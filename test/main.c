/* See LICENSE file for copyright and license details. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

void test_list1();
void test_list2();
void test_list3();
void test_list4();
void test_list5();
void test_list6();

//void
//test_map()
//{
//	map_t map = cmap_create();
//	cmap_put(&map, "hi",    "test");
//	cmap_put(&map, "hello", "test");
//	cmap_put(&map, "good",  "test");
//	cmap_put(&map, "best",  "test");
//}

int main(int argc, char** argv)
{
	test_list1();
	test_list2();
	test_list3();
	test_list4();
	test_list5();
	test_list6();

//	test_map();

	return 0;
}
