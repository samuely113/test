#include "q2.h"
int list_q2[10] = {0, 0, 0, 0, 0, 0 ,0, 0 ,0 ,0 };
int list_q2_m[10] = { 0, 2, 5, 9, 1, 3, 7, 4, 8, 6 }; 

void generate_list() {
	srand(clock());
	int n = rand() ;
	for (int i = 0; i < 10; i++) {list_q2[i] = (n*rand())%50; }
}
void print_currentList() {
	for (int i = 0; i < 10; i++) {
		printf("%d,\t", list_q2[i]);
	}printf("\n");
}
//_______________________________________________________BUBBLE SORT_______________________________________________________
void ascend_sort_list_bubble(){//keep swapping adjacent elements
	int sorted = 0, temp;
	while (!sorted) {
		for (int i = 0; i <= 8; i++) {
			if (list_q2[i] > list_q2[i + 1]) {
				temp = list_q2[i];
				list_q2[i] = list_q2[i + 1];
				list_q2[i + 1] = temp;
			}
			if (i > 0) {
				if (list_q2[i - 1] > list_q2[i]) {
					temp = list_q2[i - 1];
					list_q2[i - 1] = list_q2[i];
					list_q2[i] = temp;
				}
			}
		}
		print_currentList();
		for (int i = 0; i <= 8; i++) {
			sorted = 1;
			if (list_q2[i] > list_q2[i + 1]) { sorted = 0; break;}
		}
	}
}
//______________________________________________________SELECTION SORT_____________________________________________________
void ascend_sort_list_selection() {//push biggest element to the end
	int temp, temp_i, i, unsorted_size = 10;
	while(unsorted_size > 1){
		i = 0;
		for (int j = i; j < unsorted_size; j++) {
			if (list_q2[i] > list_q2[j]) {
				temp = list_q2[i];	list_q2[i] = list_q2[j];	list_q2[j]	= temp; 
				i = j;																
			}else if (list_q2[j] > list_q2[i]) { i = j; }
		}
		print_currentList();
		unsorted_size--;
	}
}
//______________________________________________________MERGE SORT_________________________________________________________
void split(int list[], int low, int high) {//keep splitting the list and sort the smaller subsets
	if (low < high) {
		int mid = (int)(low + ((high - low) / 2) );
		split(list, low, mid);
		split(list, mid + 1, high);
		sort_remerge(list, low, mid, high);
		print_currentList();
	}
}
void sort_remerge(int list[], int low, int mid, int high) {
	int temp, temp_i;
	for (int i = low; i <= mid; i++) {
		temp_i = i;
		for (int j = (mid+1); j <= high; j++) {
			if (list[i] > list[j]) {
				temp = list[i];	list[i] = list[j];	list[j] = temp; 
				i = j;
			}
		}i = temp_i;
	}
}
void ascend_sort_list_merge(int list[]) {
	int high = 9, low = 0;
	split(list, low, high);
}
//____________________________________________________BINARY SEARCH________________________________________________________
int binary_search_for(int value) {
	printf("performing binary search for %d\n", value);
}
void QUESTION_2() {
	generate_list();					print_currentList();
	ascend_sort_list_selection(); 		print_currentList();	printf("\n");
	generate_list();					print_currentList();
	ascend_sort_list_merge(list_q2);	print_currentList();	printf("\n");
	generate_list();					print_currentList();
	ascend_sort_list_bubble();			print_currentList();	printf("\n");
	generate_list();					print_currentList();


}