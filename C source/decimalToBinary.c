/* decimalToBinary.c -- 십진수의 값을 입력받아 그 값을 이진수로 변환하는 프로그램
   (단, 십진수의 값은 0 이상의 값으로 제한함) */
#include <stdio.h>

int main()
{
	int decimal, position, temp; //position 변수는 decimal 변수의 값을 이진수로 변환하였을 때 차지한 자릿수를 할당함
	                             //temp 변수는 position 변수의 값을 추출할 때 decimal 값이 날라가지 않도록 일시적으로 만듬 
	
	scanf("%d", &decimal);

	temp = decimal;
	
	for (position = 0; temp != 0; position++) //십진수로 이진수로 나타낼 때 2로 나누면서 몫이 0이 될 때까지 계산하므로 조건식은 temp != 0
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
