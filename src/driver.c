#include <stdio.h>
#include "linked_list.h"
void free_data(void *data)
{
    return;
}
void free_print(void *data)
{
    printf("data = %i\n", *((int*)data));
    fflush(stdout);
    return;
}
boolean data_equ(void *data_a, void *data_b)
{
    if(data_b == data_a) return 1;
    else return 0;
}
int main(int argc, char **argv)
{
    printf("Data Structure\n");
    struct linkedlist *list;
    int v,w,x,y,z;
    list = linkedlist_init();
    v = 1;
    linkedlist_insert(list, list->size - 1,&v);
    w = 2;
    linkedlist_insert(list, list->size - 1,&w);
    x = 3;
    linkedlist_insert(list, list->size - 1,&x);
    y = 4;
    linkedlist_insert(list, list->size - 1,&y);
    z = 5;
    linkedlist_insert(list, list->size - 1,&z);
    linkedlist_print(list, free_print);

    printf("search z=5 %i", linkedlist_search(list, &z, data_equ));
    linkedlist_destroy(list, free_data);
    printf("\nEnd Of Program!!");
    return 0;
}
