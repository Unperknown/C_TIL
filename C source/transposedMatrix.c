/* transposedMatrix.c -- 정사각행렬의 크기와 원소를 입력받아 그 행렬의 전치행렬을 출력하는 프로그램 */
#include <stdio.h>

int main()
{
	int size;
	
	scanf("%d", &size); // 정사각행렬의 크기를 입력받음(정사각행렬은 행과 열의 끝 번호가 같기 때문에 하나의 끝 번호만 입력해도 됨)
	
	int matrix[size][size]; //정사각행렬을 2차원 배열로 선언
	
	for (int i = 0; i < size; i++) //i는 열 번호를 나타냄
	{
		for (int j = 0; j < size; j++) //j는 행 번호를 나타냄
		{
			scanf("%d", &matrix[i][j]); //중첩 제어 구조로 각 열의 모든 행 번호 안의 원소를 입력받음
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j > i) /* 정사각행렬의 전치행렬은 행 번호와 열 번호가 같은 지점 이하부터의 
			              각 원소의 위치부터 행 번호와 열 번호가 뒤바뀐 위치의 원소와 교환하면 됨 */
			{
				matrix[i][j] = matrix[i][j] + matrix[j][i];
				matrix[j][i] = matrix[i][j] - matrix[j][i];
				matrix[i][j] = matrix[i][j] - matrix[j][i]; //원소 위치를 바꾸는 교환문
			}
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[i][j]); //전치행렬을 순서대로 출력
		
		printf("\n"); //한 열의 행을 다 출력하면 줄바꿈하여 다음 열을 출력할 수 있도록 함
	}
	
	return 0;
}