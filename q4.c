#include "q4.h"

char maze[10][10] =
{ 0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
	0,    1,    0,    0,    0,    0,    1,    1,    1,    1,
	0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
	0,    0,    0,    1,    1,    0,    1,    1,    1,    1,
	0,    1,    1,    1,    0,    0,    1,    0,    0,    1,
	1,    1,    1,    1,    0,    1,    1,    0,    0,    1,
	1,    1,    0,    1,    0,    0,    0,    0,    0,    1,
	1,    1,    0,    0,    1,    1,    1,    1,    0,    1,
	0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
	0,    1,    1,    1,    1,    1,    1,    1,    0,    0
};
char path[10][10];
int found = 0;
point *path_hd;
void move_to_next_space(int x, int y, int prev_x, int prev_y) {
	if (x == 9 && y == 9) {
		found = 1;	printf("at the end\n");	print_maze(x, y);
		return;
	}else if (((x >= 0) && (x <= 9)) && ((y >= 0) && (y <= 9))) {
		if (!found) { printf("on a %d\t", maze[x][y]); }//only print if still looking
		if (maze[x][y] == 1) {
			rmv_point();//path[x][y] = 35;
			if (!found) { printf("end\n"); }			//only print if still looking
			return;
		}else {
			for (int i_x = 1; i_x >= -1; i_x--) {
				if (!found) {
					for (int i_y = 1; i_y >= -1; i_y--) {
						if (found) {
							//printf("FOUND\n"); 
							break;
						}else if ((!found) && (((x + i_x) >= 0) && ((x + i_x) <= 9) && ((y + i_y) >= 0) && ((y + i_y) <= 9))) {//so long as it exists
							//print_maze(x, y);
							if (((x + i_x) != x) && ((x + i_x) != prev_x)) {// so long as it moves from its position
								//printf("from (%d, %d) to (%d, %d)\n", x, y, (x + i_x), y); 
								if (!found) { add_point((x + i_x), y); }//path[(x + i_x)][y] = 219;
								move_to_next_space((x + i_x), y, x, y);
							}
							if (((y + i_y) != y) && ((y + i_y) != prev_y)) {// so long as it moves from its position
								//printf("from (%d, %d) to (%d, %d)\n", x, y, x, (y + i_y));
								if (!found) { add_point(x, (y + i_y)); }//path[x][(y + i_y)] = 219;
								move_to_next_space(x, (y + i_y), x, y);
							}
						}//while (1) { printf("next iteration: "); getchar(); break; }
					}
				}
			}
		}
	}
}
void print_maze(int x, int y) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (path[i][j == 219]) { printf("%c\t",path[i][j]); } else { printf("%d\t", maze[i][j]); }
		}printf("\n");
	}printf("\n");
}
void add_point(int x, int y) {
	point *traverser = path_hd;
	point *next_point = (point *)malloc(sizeof(point));
	while (traverser->next != NULL) {	traverser = traverser->next;}
	traverser->next = next_point;
	next_point->x = x;	next_point->y = y;	next_point->next = NULL;
}
void rmv_point() {
	point *traverser = path_hd;
	while (traverser->next != NULL) { traverser = traverser->next; }
	free(traverser->next);
}
void solve_maze() {
	point *traverser;
	path_hd = (point *)malloc(sizeof(point));

	path_hd->x = 0; path_hd->y = 0; path_hd->next = NULL;
	for (int i = 0; i < 10; i++) {//initialize path
		for (int j = 0; j < 10; j++) {
			path[i][j] = 35;	printf("%d", maze[i][j]);
		}printf("\n");
	}printf("\nsolving maze\n");

	move_to_next_space(0, 0, 0, 0);
	traverser = path_hd;
	while (traverser != NULL) {
		printf("(%d,%d)\n", traverser->x, traverser->y);
		traverser = traverser->next;
	}
}