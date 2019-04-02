#include "q1.h"


void linked_list_initialize() { 
	ll_head = (node *)malloc(sizeof(node)); 
	ll_head->value = 0;	ll_head->next = NULL;
}
void linkedList_add(int value, node *after_node) {
	printf("Linked List Add called\n");
	node *new_node = (node*)malloc(sizeof(node));//allocate memory for new node
	new_node->value		= value;
	new_node->next		= after_node->next;
	after_node->next	= new_node;
}
int linkedList_remove(node *item) {
	int value, found = 0;
	node *traverser = ll_head;
	node *removed_item;
	printf("Linked List Remove called:");
	while (traverser != NULL) {
		if (traverser->next == item) {
			removed_item = traverser->next; value = traverser->next->value;
			traverser->next = traverser->next->next;
			free(removed_item); found = 1;
			printf(" %d removed\n", value); break;
		}else { traverser = traverser->next; }
	}	if (!found) { printf("item not found"); }
	return value;
}
int popList() {
	int value = ll_head->next->value;
	node *removed_node = ll_head->next;
	printf("popped: %d removed\n", value);
	ll_head->next = ll_head->next->next;
	free(removed_node);
	return value;
}
void print_linkedList() {
	node *current_node = (node *)malloc(sizeof(node));
	current_node = ll_head;
	while(1){
		printf("%d, ", current_node->value);
		current_node = current_node->next;  
		if (current_node == NULL) { break; }
	} 
	printf("\n");
}
void enqueueList(int value) {
	node *traverser = ll_head;
	node *item = (node *)malloc(sizeof(node)); item->value = value;
	printf("%d enqueued\n", value);
	while (traverser->next != NULL) { traverser = traverser->next; }
	traverser->next = item;
	item->next = NULL;
}
void pushList(int value) {
	node *item = (node *)malloc(sizeof(node));
	printf("%d pushed\n", value);
	item->value = value;
	item->next = ll_head->next;
	ll_head->next = item;
}
void QUESTION_1() {
	linked_list_initialize();
	linkedList_add(1, ll_head);						print_linkedList();
	for (int i = 0; i < 10; i++) { enqueueList(i); }	print_linkedList();
	for (int i = 0; i < 10; i++) { pushList(i); }	print_linkedList();
	linkedList_add(2, ll_head->next);				print_linkedList();
	popList(ll_head->next);							print_linkedList();
	linkedList_remove(ll_head->next->next);			print_linkedList();
}