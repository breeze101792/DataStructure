#include <stdlib.h>
#include "hash_table.h"
#include "linked_list.h"
/*
typedef struct htnode
{
    struct htnode *next;
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
    struct linkedlist *new_table;
    new_table = malloc(sizeof(struct linkedlist) * size);
    new_table->size = size;
    return new_table;
}
//TODO check if it work
void hashtable_destory(htable *dtable, void (data_free)(void *data))
{
    int counter;
    struct linkedlist *current;
    counter = dtable->size;
    while(counter--)
    {
        linkedlist_destroy(current + counter, data_free);
    }
}//TODO
void hashtable_add(htable *atable, void *data)
{

    int index;
    struct linkedlist *new_node;
    index = hashtable_hash(atable->size, data);


}
unsigned int hashtable_hash(unsigned int size, void *data)
{
    return 0;
}
