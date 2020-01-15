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
* `linit`: creates an empty list - returns pointer to list
* `linsert`: inserts data to list - returns pointer to added element
* `lappend`: appends data to list - returns pointer to added element
* `lconcat`: appends list two to list one
* `lget`: returns element by index
* `lput`: replaces data in element by index (frees old data)
* `lrm`: removes element via element-pointer - returns `0` if succeded, `-1` if failed
* `lrmf`: removes first element in list (throws error if list is empty)
* `lrml`: removes last element in list (throws error if list is empty)
* `lfind`: finds element with specific data - returns pointer to element (`NULL` if not exits)
* `lrev`: reverses the given list
* `lprint`: prints list
* `ltoa` : list to array
* `lfinit`: deletes list (choose if data should also be freed)

### Known flaws
Make sure your saved data was initialized via `malloc`, otherwise it will come to `invalid pointer`-errors within `lrm`, `lrmf`, `lrml` and `lfinit`.