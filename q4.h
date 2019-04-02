#ifndef Q4_H
#define Q4_h
#include <stdio.h>
typedef struct path_point {
	int x;
	int y;
	struct path_point *next;
}point;
void move_to_next_space(int, int, int, int);
void solve_maze();
void print_maze(int, int);
void add_point(int, int);
void rmv_point();
#endif
