/* hourGlass.c -- 역피라미드를 출력하는데 열의 중간 부분부터 피라미드를 출력하는 프로그램 */
#include <stdio.h>

int main()
{
	int i, j, k, size, temp;
	
	scanf("%d", &size); //역피라미드-피라미드 구조의 끝 열 번호 입력 받기(줄 크기)
	
	if (size % 2 != 0) //홀수인지 짝수인지 판별 <= 짝수이면 역피라미드와 피라미드 출력이 어려움
	{
		for (i = 0; i <= size / 2; i++) //역파리미드를 반복문을 통해 중간까지 순차적으로 출력함
		{
			temp = i; //후에 역피라미드를 역순으로 출력하기 위해 임시 변수에 넣음
			for (j = 0; j < i; j++) printf(" "); //역피라미드의 공백 부분 <= 줄 크기가 커질수록 공백이 커짐
			for (k = 0; k < size - 2 * i; k++) printf("*"); //역피라미드의 별 부분 <= 줄 크기가 커질수록 별 개수가 적어짐
			printf("\n"); //줄바꿈을 하여 피라미드 각 열의 출력을 보기 좋게 함
		}
		for (int i = size / 2 + 1; i < size; i++) //피라미드를 반복문을 통해 중간부터 마지막까지 순차적으로 출력함
		{
			temp--; //실제적으로 i 변수에 의해 피라미드가 출력되므로 i와 비슷한 temp 변수를 계속 줄이면서 피라미드를 출력함
			for (j = 0; j < temp; j++) printf(" ");
			for (k = 0; k < size - 2 * temp; k++) printf("*");
			printf("\n");
		}
	}
	else
		printf("Please input odd number instead."); //짝수이면 홀수를 입력하라고 경고함

	return 0;
}