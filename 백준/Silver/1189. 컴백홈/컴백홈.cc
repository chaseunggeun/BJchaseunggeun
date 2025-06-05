#include <iostream>
using namespace std;

char map[5][5];
int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
int R, C, K;
int sum = 0;

void dfs(int row, int col, int cnt)
{
	if (cnt == K)
	{
		if (row == 0 && col == C - 1)
		{
			sum++;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nRow = row + dy[i];
		int nCol = col + dx[i];

		if (nRow < 0 || nCol < 0 || nRow >= R || nCol >= C || map[nRow][nCol] == 'T') continue;

		map[row][col] = 'T';
		dfs(nRow, nCol, cnt + 1);
		map[row][col] = '.';
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
	{
		cin >> map[i];
	}

	dfs(R - 1, 0, 1);
	cout << sum;

}