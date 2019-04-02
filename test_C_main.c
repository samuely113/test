#include <stdio.h>
#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
/*	1.	make a linked list
	2.	make a bianry search tree
	3.	make a base64 encoder
	4.	make a maze solver */
typedef struct _list_item {
	int value;
	struct list_item* next;
} list_item;

void del_item(list_item *root, int val)
{
	list_item *traverser = root;
	list_item *next_item;
	while (traverser->next != 0) {
		if (root->value == val) {
			printf("removed %d\n", root->value);
			root = root->next;
		}else {
			next_item = traverser->next;
			if (next_item->value == val) {
				printf("removed %d\n", next_item->value);
				traverser->next = next_item->next;
				//free(next_item);
			}
		}
		traverser = traverser->next;
	}
}

void print_list(list_item *root)
{
	while (root != 0) {
		printf("%d\n", root->value);
		root = root->next;
	}
}
int table[5] = { 1,3,5,7,9 };
int BINARYsearch(int *table, int sz, int key){
	int lo_value = 0;
	int hi_value = sz;
	int index;
	while (1) {
		index = (int)((hi_value + lo_value) / 2);
		if (lo_value >= hi_value) {
			break;
		}
		else if (table[index] < key) {
			lo_value++;
		}else{
			hi_value = index;
		}
	}
	printf("index is %d", lo_value);
	return lo_value;
}
int fn(int v)
{
	if (v == 1 || v == 0)
		return 1;
	if (v % 2 == 0)
		return fn(v / 2) + 2;
	else
		return fn(v - 1) + 3;
}

int main()
{
	//solve_maze(0, 0, 0, 0);
	
	list_item *list_hd = (list_item *)malloc(sizeof(list_item));
	list_item list[6];
	
	list[0].value = 1; list[0].next = list + 1;
	list[1].value = 2; list[1].next = list + 2;
	list[2].value = 3; list[2].next = list + 3;
	list[3].value = 4; list[3].next = list + 4;
	list[4].value = 5; list[4].next = list + 5;
	list[5].value = 6; list[5].next = 0;

	list_hd = &list[0];
	printf("test to delete list item whose value is 3\n");
	del_item(list_hd, 3);//&list
	print_list(list_hd);
	BINARYsearch(table, 5, 9);
	unsigned int x = 0x00112233;
	unsigned int y = 0x00000000;
	printf("\n%d\n", sizeof(x));
	b64_encode(x, b64length(sizeof(x)*8), &y);
	printf("%d", y);
	while (1) { getchar(); break; }

}