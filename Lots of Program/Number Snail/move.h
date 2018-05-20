#include <stdio.h>

extern int n, m, i, j, choose;
int a[100][100];

void start_point(int * i, int * j);
void follow_snail(int n, int m);
void arr_print(int n, int m);
void clear();
void set_way(int a);
void end();
void bar();