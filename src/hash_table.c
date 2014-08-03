#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"
#include "linked_list.h"
/*
typedef struct htnode
{
    unsigned int key;
    void *data;
} node;
static inline node* htnode_create(void *data);

static inline node* htnode_create(void *data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}*/
/* Hash Table Operation */
htable* hashtable_create(unsigned int size)
{
    int counter;
    htable *new_httable;
    new_httable = malloc(sizeof(htable));
    new_httable->size = size;
    new_httable->table = malloc(sizeof(struct linkedlist) * size);

    for(counter = 0;counter < size;counter++)
    {
        linkedlist_init(new_httable->table + counter);
        printf("linkedlist init: %i\n", counter);
    }

    return new_httable;
}
//TODO check if it work
void hashtable_destory(htable *dtable, void (data_free)(void *data))
{
    int counter;
    counter = dtable->size;
    while(counter--)
    {
        linkedlist_destroy(dtable->table + counter, data_free);
    }
    free(dtable);
}
void hashtable_add(htable *atable, void *data)
{
    int index;
    struct linkedlist *ilist;
    index = hashtable_hash(atable->size, data);
    ilist = atable->table + index;
    linkedlist_insert(ilist, ilist->size, data);
}
unsigned int hashtable_hash(unsigned int size, void *data)
{
    printf("hasht function: %u\n", *((unsigned int*)data) % size);
    fflush(stdout);
    return *((unsigned int*)data) % size;
}
