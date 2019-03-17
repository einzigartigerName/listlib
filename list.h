#include <stddef.h>
#include <stdio.h>

#define ERROR(msg) { fprintf(stderr, "ERROR: %s - %s", __func__, (msg)); exit(EXIT_FAILURE); } while(0)

struct list_elem {
    struct list_elem    *next;	    // Next Element in List
    void	            *data;	    // Data
};

typedef struct list {
    size_t              size;       // Size of List
	struct list_elem    *first;     // First Element of List
	struct list_elem    *last;  	// Last Element of List
} list_t;

/* function prototypes */
list_t                  *list_init ();
struct list_elem        *list_insert (list_t *list, void *data);
struct list_elem        *list_append (list_t *list, void *data);
int                     list_remove (list_t *list, struct list_elem *elem);
void                    list_finit (list_t *list);
void                    list_print (list_t *list, void (*print_elem) (void *));
struct list_elem        *list_find (list_t *list, void *data, int (*cmp_elem) (const void *, const void *));
void*                   list_remove_first(list_t *li);
