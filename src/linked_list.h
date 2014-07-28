#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
typedef unsigned char boolean;
struct llnode;

typedef struct linkedlist
{
  struct llnode* head;
  struct llnode* tail;
  unsigned int size;
} llist;


llist* linkedlist_init();
void linkedlist_destroy(llist *dlist, void (*data_free)(void*));
void linkedlist_print(llist *plist, void (*data_print)(void*));
struct llnode* linkedlist_getnode(llist *plist, unsigned int index);
int linkedlist_search(llist *plist, void *data, boolean (*data_equ)(void *data_a, void *data_b));
/*insert index: -1 for insert in font of the first node*/
void linkedlist_insert(llist *ilist, unsigned int index, void *data);
void linkedlist_remove(llist *rlist, unsigned int index);
boolean linkedlist_isempty(llist *ielinst);
#endif // LINKED_LIST_H_INCLUDED
