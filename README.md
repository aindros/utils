# c-utils

A utility toolkit for the C language. These are the main features:

* lists - you can manage lists in a simple way.

Upcoming features:

* maps - you can create maps with a key ad a value. The only limitation is the
key must be a string.

## Lists
### How to create a list
```
list_t my_list = clist_create();
```
### How to add new data to a list
```
char *my_data = "My data!";
clist_add(&my_list, my_data, strlen(my_data) + 1);
```
If you store strings, you can just use `strlen(char *) + 1`, but if you want use
other types of data, you can just do:
```
struct my_struct *s1 = ...
clist_add(&my_list, s1, sizeof(s1));
```
