#include <stdio.h>
#include "linked_list.h"
#include "hash_table.h"
void free_data(void *data)
{
    printf("delete %i\n", *((int*)data));
    return;
}
void data_print(void *data)
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
    v = 1, w = 2, x = 3, y = 4, z = 5;

    list = linkedlist_init();
/*    linkedlist_insert(list, list->size - 1,&v);
    linkedlist_insert(list, list->size - 1,&w);
    linkedlist_insert(list, list->size - 1,&x);
    linkedlist_insert(list, list->size - 1,&y);
    linkedlist_insert(list, list->size - 1,&z);
    linkedlist_print(list, data_print);

    linkedlist_remove(list, 4);
    linkedlist_print(list, data_print);

    printf("search z=5\nindex = %i\n", linkedlist_search(list, &z, data_equ));
    linkedlist_destroy(list, free_data);
*/

    printf("Hash table!\n");
    struct hashtable *mytable;
    int htsize = 17;
    mytable = hashtable_create(htsize);
    hashtable_add(mytable, &v);
    list = mytable->table + 1;
    linkedlist_print(list, data_print);












    printf("\nEnd Of Program!!");
    return 0;
}
