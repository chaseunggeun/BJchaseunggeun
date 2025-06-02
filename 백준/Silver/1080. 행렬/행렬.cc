#include <iostream>

using namespace std;

char arr[50][50];
char goal[50][50];
int row, col;
int cnt = 0;

void input();
void solution();
void flip(int startRow, int startCol);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	solution();
	
}
void solution()
{
	for (int i = 0; i < row - 2; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (arr[i][j] != goal[i][j])
			{
				flip(i,j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] != goal[i][j])
			{
				cout << -1;
				return;
			}
		}
	}
	cout << cnt;
}
void flip(int startRow, int startCol)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[startRow + i][startCol + j] == '0')
			{
				arr[startRow + i][startCol + j] = '1';
			}
			else
			{
				arr[startRow + i][startCol + j] = '0';
			}
		}
	}
}

void input()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < row; i++)
	{
		cin >> goal[i];
	}
}
