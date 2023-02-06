#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
int a[8][8];
int bN;
void out(FILE* fout);
void queen(int x, int y, int n, FILE * fout);
void attack(int x, int y, int z);
int main(void)
{
	FILE * fout;
	fout = fopen("output.txt", "w");
	int n = 0;
	int a[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = 0;
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{

			if (bN == 7) break;
			queen(i, j, 0, fout);
			
		}
	return 0;
}

void out(FILE* fout)
{
	fprintf(fout, "%c", '\n');
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] < 50)
			{
				
				fprintf(fout, "%d", a[i][j]);
				fprintf(fout, "%c", ' ');
				fprintf(fout, "%c", ' ');
				fprintf(fout, "%c", ' ');
			}
			else
			{
				fprintf(fout, "%d", a[i][j]);
				fprintf(fout, "%c", ' ');

			}
		}
		fprintf(fout, "%c", '\n');
	}
}

void queen(int x,int y, int n, FILE *fout)
{   
	if (bN == 7)
		return;
	if ((x == 4) && (y == 7))
		x = 4;
	a[x][y] = 100;
	attack(x, y, 1);
	
	for (int i = 0;i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (n == 7) {

				bN = 7;
				out(fout);
				return;
			}
			if (a[i][j] == 0)
			{

				queen(i, j, n + 1, fout);

			}
		}
	if (n != 7)
	{
		attack(x, y, -1);
		a[x][y] = 0;
		return;
	}
}


void attack(int x, int y, int z)
{


	int cnt = 1;
	for (int i = 0; i < 8; i++)
		if (i != x) a[i][y] += z;
	for (int i = 0; i < 8; i++)
		if (i != y) a[x][i] += z;
	
	int k = 0;
	for (int i = y; i < 8; i++)
	{
		if ((x + k < 8)&&(y + k < 8) && (i!=y))
		{
			if (a[x + k][y + k] == 100) 
			{
				a[x + k][y + k] = 100;
			}
			a[x + k][y + k] += z;
		}
		k++;
	}
	k = 0;
	for (int i = y; i >=0; i--)
	{
		if ((x - k >= 0)&&(y - k >= 0) && (i != y))
		{
			if (a[x - k][y - k] == 100)
			{
				a[x - k][y - k] = 100;
			}

			a[x - k][y - k]+=z;
		}
		k++;
	}

	 k = 0;
	for (int i = y; i >= 0; i--)
	{
		if ((x + k < 8)&&(y - k >= 0) && (i != y))
		{
			if (a[x + k][y - k] == 100)
			{
				a[x + k][y - k] = 100;
			}
			
			a[x + k][y - k] += z;
		}
		k++;
	}
	k = 0;
	for (int i = y; i >= 0; i--)
	{
		if ((x - k >= 0)&&(y + k < 8) && (i != y))
		{
			if (a[x - k][y + k] == 100)
			{
				a[x - k][y + k] = 100;
			}

			a[x - k][y + k] +=z;
		}
		k++;
	}
}
