#ifndef Q1_H
#define Q1_H
#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list_node {
	int value;
	struct linked_list_node *next;
}node;
node *ll_head;
void linked_list_initialize();
void linkedList_add(int, node *);
int linkedList_remove(node *);
int popList();
void print_linkedList();
void enqueueList(int);
void pushList(int);
void QUESTIION_1();
#endif
