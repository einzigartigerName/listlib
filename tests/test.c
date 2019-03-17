#include "../src/list.h"
#include <stdio.h>

#define ERROR(msg) { fprintf(stderr, "ERROR: %s - %s", __func__, (msg)); exit(EXIT_FAILURE); } while(0)

void test_append();
void test_insert();

int main(int argc, char* argv[]){
    printf("Expected: Count from zero to two.\n\n");

    printf("---------- Result ----------\n\n-- APPEND --\n");
    test_append();
    printf("\n-- INSERT --\n");
    test_insert();

    return 0;
}

void print_elem(void *data){
    printf("%s\n", data);
}

void test_append(){
    list_t *li = list_init();

    list_append(li, "zero");
    list_append(li, "one");
    list_append(li, "two");

    list_print(li, print_elem);

    list_finit(li);
}

void test_insert(){
    list_t *li = list_init();

    list_insert(li, "two");
    list_insert(li, "one");
    list_insert(li, "zero");

    list_print(li, print_elem);
    list_finit(li);
}

