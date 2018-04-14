/* mineSweeper.c -- */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, column;

	scanf("%d %d", &row, &column);

	char **mneS = malloc(sizeof(char *) * column);
	
	for (int i = 0; i < column; i++)
		mneS[i] = malloc(sizeof(char) * row);

	for (int i = 0; i < column; i++)
		scanf("%s", mneS[i]);

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mneS[i][j] == '*')
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						if (k >= 0 && k < column && l >= 0 && l < row)
						{
							if (mneS[k][l] == '.')
								mneS[k][l] = '1';
							else if (mneS[k][l] >= '1')
								mneS[k][l]++;
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mneS[i][j] == '.')
				mneS[i][j] = '0';
		}
	}
	
	for (int i = 0; i < column; i++)
		printf("%s\n", mneS[i]);
	
	for (int i = 0; i < column; i++)
		free(mneS[i]);

	free(mneS);

	return 0;
}
