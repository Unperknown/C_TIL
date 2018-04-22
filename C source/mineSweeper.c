/* mineSweeper.c -- 지뢰 찾기 게임에서 각 위치의 지뢰 갯수 출력하기*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, column;

	scanf("%d %d", &row, &column); //row와 column 변수에 각각 가로 크기와 세로 크기 입력

	char **mneS = malloc(sizeof(char *) * row);
	
	for (int i = 0; i < row; i++)
		mneS[i] = malloc(sizeof(char) * column); //mneS 포인터에 가로와 세로 크기 만큼의 동적 메모리 할당을 통해 2차원 배열처럼 사용

	for (int i = 0; i < row; i++)
		scanf("%s", mneS[i]); //각 열에 지뢰가 있으면 *, 아니면 .을 행 크기 만큼 입력함

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) // 각 열의 행 위치를 차례대로 따라가서
		{
			if (mneS[i][j] == '.')
				mneS[i][j] = '0';
			else if (mneS[i][j] == '*') //그 위치가 지뢰이면
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++) //그 위치에서 한 칸씩 떨어진 모든 위치들을 따라감
					{
						if (k >= 0 && k < row && l >= 0 && l < column) //(단, 그 위치는 배열 인덱스 값에서 벗어나면 안됨)
						{
							if (mneS[k][l] == '.' || mneS[k][l] == '0')
								mneS[k][l] = '1'; //한 칸 떨어진 위치의 값이 '.'('0')이면 지뢰가 있음을 보여주기 위해 '1' 할당
							else if (mneS[k][l] >= '1')
								mneS[k][l]++; //이미 지뢰가 있음을 보여주는 '1'을 할당했으면 증가시켜 지뢰 갯수를 늘림
							//그 외의 경우는 '*'인 경우이므로 굳이 할당할 필요가 없음
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < row; i++)
		printf("%s\n", mneS[i]); //각 위치의 지뢰 또는 지뢰 갯수 출력
	
	for (int i = 0; i < row; i++)
		free(mneS[i]);

	free(mneS); //메모리 해제하기

	return 0;
}