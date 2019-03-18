#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define ERROR(msg) { fprintf(stderr, "ERROR: %s - %s", __func__, (msg)); exit(EXIT_FAILURE); } while(0)

list_t *list_init (){
    list_t *li = (list_t*) malloc(sizeof(list_t));
    if (li == NULL)
        ERROR("Can not malloc list.");

    li->first = NULL;
    li->last = NULL;
    li->size = 0;
    
    return li;
}

struct list_elem *list_insert (list_t *list, void *data){
    // Create list_elem
    struct list_elem *in = (struct list_elem*) malloc(sizeof(struct list_elem));
    if(in == NULL)
        ERROR("Can not malloc list_elem.");
        
    in->data = data;
    in ->next = list->first;

    // list is empty ->'in' as last element
    if(list->first == NULL){
        list->last = in;
    }

    list->first = in; 
    list->size += 1;

    return in;
}

struct list_elem *list_append (list_t *list, void *data){
     // Create list_elem
    struct list_elem *app = (struct list_elem*) malloc(sizeof(struct list_elem));
    if(app == NULL)
        ERROR("Can not malloc list_elem.");
        
    app->data = data;
    app->next = NULL;

    // list is empty ->'app' is first and last element 
    if(list->first == NULL){
        list->first = app;
    }   else{
        list->last->next = app;
    }

    list->last = app;
    list->size += 1;

    return app;
}

struct list_elem *list_find (list_t *list, void *data, int (*cmp_elem) (const void *, const void *)){
    struct list_elem *current = list->first;

    while(current != NULL){
        if(cmp_elem(current->data, data) == 0)
            return current;

        current = current->next;
    }

    return NULL;
}


/*
* @param list_t
* @param list_elem
* @return int: success -> 0; failure -> -1
*/
int list_remove (list_t *list, struct list_elem *elem){
    if (list->first == NULL || elem == NULL)
        return -1;

    struct list_elem *current = list->first;

    // check first element
    if(current == elem){
        list->first = current->next;
        free(elem);
        return 0;
    }
    // Check in rest of list
    while(current->next != NULL){
        if(current->next == elem){
            current->next = elem->next;
            free(elem);
            return 0;
        }
        current = current->next;
    }

    return -1;
}

void list_print (list_t *list, void (*print_elem) (void *)){
    struct list_elem *current = list->first;
    while(current != NULL){
        print_elem(current->data);
        current = current->next;
    }
}

void list_finit (list_t *list){
    if(list->first == NULL){
        free(list);
        return;
    }

    struct list_elem *current = NULL;
    while (list->first != list->last) {
        current = list->first;
        list->first = current->next;
        free(current);
    }

    free(list->first);
    free(list);
}