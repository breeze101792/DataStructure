#include <stdlib.h>
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
    htable *new_table;
    new_table = malloc(sizeof(htable));
    new_table->table = malloc(sizeof(struct linkedlist) * size);
    new_table->size = size;
    counter = 0;
    while(counter < size)
    {
        linkedlist_init(new_table->table + counter);
        counter++;
    }
    return new_table;
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
}//TODO
void hashtable_add(htable *atable, void *data)
{

    int index;
    struct linkedlist *ilist;
    index = hashtable_hash(atable->size, data);
    ilist = atable->table + (index - 1);
    linkedlist_insert(ilist, ilist->size - 1, data);
}
unsigned int hashtable_hash(unsigned int size, void *data)
{
    return *((unsigned int*)data) / size;
}
