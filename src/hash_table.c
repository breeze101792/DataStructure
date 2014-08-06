#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"
#include "linked_list.h"

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
    }

    return new_httable;
}
//
void hashtable_destory(htable *dtable, void (data_free)(void *data))
{
    int counter;
	counter = 0;
	while(counter < dtable->size)
	{
		if(!linkedlist_isempty(dtable->table + counter))
		{
			linkedlist_print(dtable->table + counter, data_free);
		}
		counter++;
	}
    free(dtable);
}
void hashtable_add(htable *atable, void *data)
{
    int index;
    struct linkedlist *ilist;
    index = hashtable_hash(atable->size, data);
    ilist = atable->table + index;
    linkedlist_insert(ilist, ilist->size - 1, data);
}
unsigned int hashtable_hash(unsigned int size, void *data)
{
    return *((unsigned int*)data) % size;
}

void hashtable_print(htable *atable, void (*data_print)(void *data))
{
	int counter;
	counter = 0;
	while(counter < atable->size)
	{
		if(!linkedlist_isempty(atable->table + counter))
		{
			printf("\n%i: ", counter);
			linkedlist_print(atable->table + counter, data_print);
		}
		counter++;
	}

}
