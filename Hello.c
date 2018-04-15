#include <stdio.h>

void hello_world();
int main()
{
	hello_world();
	printf("\nAnything else?");
	
	return 0;
}

void hello_world()
{
	printf("Hello, world!");
}