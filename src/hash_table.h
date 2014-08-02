#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED
#include "linked_list.h"
//struct htnode;

typedef struct hashtable
{
    struct linkedlist *table;
    unsigned int size;
} htable;

htable* hashtable_create(unsigned int size);
void hashtable_destory(htable *dtable, void (data_free)(void *data));
unsigned int hashtable_hash(unsigned int size, void *data);
void hashtable_add(htable *atable, void *data);



#endif // HASH_TABLE_H_INCLUDED
