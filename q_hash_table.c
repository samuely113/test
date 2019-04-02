#include "q_hash_table.h"
#define TABLESIZE 7//must be prime nunmber
int hashtable[TABLESIZE] = { 0 };
int empty[TABLESIZE] = { 0 };


/*
get key
for (i)
compute hash (index = (k+i^2) % SIZE)
if hashtable[index] is empty
	insert key at hashtable[index]
else
	i ++ until the max index of hashtable
	recompute hash
*/
int quadratic_probing_insert(int *hashtable, int *empty, int key){
	int hash_index;
	for (int i = 0; i < TABLESIZE; i++) {
		hash_index = (key + (i*i)) % TABLESIZE;
		if (hashtable[hash_index] == empty[hash_index]) {
			hashtable[hash_index] = key;
			break;
		}
	}
	return -1;
}
