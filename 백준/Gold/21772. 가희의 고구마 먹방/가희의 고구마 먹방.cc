#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[101][101];
int R, C, T;
int startX, startY;

int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int maxGoguma = 0;


void dfs(int x, int y, int depth, int cnt)
{

	// 고구마 있으면 먹고
	// 제자리면 안먹고

	// 최대거리 이동했으면 cnt 리턴

	// 최대거리 아직 아닐 때
	// 가능한 곳 dfs

	// 먹었으면 .으로
	// 백트래킹때 다시 S로

	if (depth == T)
	{
		if (maxGoguma < cnt)
		{
			maxGoguma = cnt;
		}
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= C && ny <= R && map[ny][nx] != '#')
		{
			bool eat = false;
			int ncnt = cnt;
			if (map[ny][nx] == 'S' && !(dx[i] == 0 && dy[i] == 0))
			{
				ncnt++;
				map[ny][nx] = '.';
				eat = true;
			}

			dfs(nx, ny, depth + 1, ncnt);

			if (eat)
			{
				map[ny][nx] = 'S';
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	for (int y = 1; y <= R; y++)
	{
		for (int x = 1; x <= C; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 'G')
			{
				startX = x;
				startY = y;
			}
		}
	}

	dfs(startX, startY, 0, 0);

	cout << maxGoguma;
}