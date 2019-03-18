# listlib

This is a C-Implementation of an universal linked list.\
It can handle every type of data you want, by handling just the pointer to it.\
To print the output, you have to provide your own print methode handling our data.\
To find an element within the list, a comparison methode must be provided by you.

### Usage
Place `list.h` and `list.c` in your project and include `list.h`
```C
#include "path/to/list.h"
.
.
```
Now you can use the provided function in your project:
* `list_init`: creates an empty list - returns pointer to list
* `list_insert`: inserts data to list - returns pointer to added element
* `list_append`: appends data to list - returns pointer to added element
* `list_remove`: removes element via element-pointer - returns `0` if succeded, `-1` if failed
* `list_find`: finds element with specific data - returns pointer to element ('NULL' if not exits)
* `list_print`: prints list
* `list_finit`: deletes list