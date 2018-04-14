#include <stdio.h>

int main()
{
	int decimal, position, temp;
	
	scanf("%d", &decimal);

	temp = decimal;
	
	for (position = 0; temp != 0; position++)
		temp /= 2;
	
	int binary[position];
	
	for (position = 0; decimal != 0; position++)
	{
		binary[position] = decimal % 2;
		decimal /= 2;
	}
	
	for (int i = position - 1; i >= 0; i--)
		printf("%d", binary[i]);
	
	return 0;
}
