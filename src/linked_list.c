#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

typedef struct llnode
{
//    struct llnode *pre;
    struct llnode *next;
    void *data;
} node;

static node* llnode_create(void *data);
/* node operation */
static node* llnode_create(void *data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
/* Linked List Function */

llist *linkedlist_init()
{
    llist *list = malloc(sizeof(llist));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
void linkedlist_destroy(llist *dlist, void (*data_free)(void*))
{
    node *tmp;
    while(dlist->size)
    {
        tmp = dlist->head;
        dlist->head = dlist->head->next;
        data_free(tmp->data);
        free(tmp);
        dlist->size -= 1;
    }
    free(dlist);
}
void linkedlist_print(llist *plist, void (*data_print)(void*))
{
    int counter;
    node *tmp;
    tmp = plist->head;
    counter = plist->size;
    while(counter && tmp != NULL)
    {
        data_print(tmp->data);
        tmp = tmp->next;
        counter--;
    }
}
struct llnode* linkedlist_getnode(llist *slist, unsigned int index)
{
    if(index == slist->size - 1) return slist->tail;
//    else if(index >= plist->size || index < 0)
    int counter;
    node *tmp;
    tmp = slist->head;
    counter = 0;
    while(counter != index)
    {
        tmp = tmp->next;
        counter++;
    }
    return tmp;
}
int linkedlist_search(llist *slist, void *data, boolean (*data_equ)(void *data_a, void *data_b))
{
    if(!linkedlist_isempty) return -1;
    int counter;
    node *tmp;
    tmp = slist->head;
    counter = 0;
    while(counter < slist->size && tmp != NULL)
    {
        if(data_equ(tmp->data, data))return counter;
        tmp = tmp->next;
        counter++;
    }
    return -2;
}
void linkedlist_insert(llist *ilist, unsigned int index, void *data)
{
    if(ilist->head == NULL)
    {
        ilist->head = llnode_create(data);
        ilist->tail = ilist->head;
    }
    else if(index == -1)
    {
        node *tmp;
        tmp = llnode_create(data);
        tmp->next = ilist->head;
        ilist->head = tmp;
    }
    else if(index < ilist->size - 1 && index >= 0)
    {
        node *tmp, *tmp_new;
        tmp = linkedlist_getnode(ilist, index);
        tmp_new = llnode_create(data);
        tmp_new->next = tmp->next;
        tmp->next = tmp;
    }
    else if(index == ilist->size - 1)
    {
        ilist->tail->next = llnode_create(data);
        ilist->tail = ilist->tail->next;
    }
    ilist->size++;
}
void linkedlist_remove(llist *rlist, unsigned int index)
{
    if(!linkedlist_isempty) return;
    if(index == 0)
        if(rlist->size == 1)//after delete, it is empty!
        {
            free(rlist->head);
            rlist->head = NULL;
            rlist->tail = NULL;
        }
        else
        {
            node *tmp;
            tmp = rlist->head;
            rlist->head = rlist->head->next;
            free(tmp);
        }
    else
    {
        node *tmp, *tmp_d;
        tmp = linkedlist_getnode(rlist, index - 1);
        tmp_d = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp_d);
    }
    rlist->size -= 1;
}
boolean linkedlist_isempty(llist *ielist)
{
    if(ielist->head == NULL) return 1;//true
    else return 0;//false
}
