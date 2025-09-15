#include <iostream>
#include <cstring> 
using namespace std;

char arr[501][501];
int visit[501][501][4];

int N, M, r, c;
pair<int, int> ans = { 0, 0 };
bool vo;
// 0, 1,2,3 왼하오상

// 1
//2 0
// 3
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1,0 };
char dir[4] = { 'L','D', 'R', 'U' };

void dfs(int row, int col, int cnt, int dir, int firstDir)
{
	if (row<1 || col<1 || row>N || col>M || arr[row][col] == 'C')
	{
		if (cnt > ans.second)
		{
			ans.second = cnt;
			ans.first = firstDir;
		}
		return;
	}

	if (visit[row][col][dir])
	{
		vo = true;
		ans.first = firstDir;
		return;
	}

	visit[row][col][dir] = 1;
	
	int ndir = dir;
	if (arr[row][col] == '\\')
	{
		if (dir == 0) ndir = 3;
		else if (dir == 1) ndir = 2;
		else if (dir == 2) ndir = 1;
		else if (dir == 3) ndir = 0;
	}
	else if (arr[row][col] == '/')
	{
		if (dir == 0) ndir = 1;
		else if (dir == 1) ndir = 0;
		else if (dir == 2) ndir = 3;
		else if (dir == 3) ndir = 2;
	}

	dfs(row + dr[ndir], col + dc[ndir], cnt+1, ndir, firstDir);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> r >> c;
	for (int i = 3; i >= 0; i--)
	{
		memset(visit, 0, sizeof(visit));
		vo = false;

		dfs(r, c, 0, i, i);

		if (vo)
		{
			ans.first = i;
			break;
		}
	}

	cout << dir[ans.first] << "\n";
	if (vo)
	{
		cout << "Voyager";
	}
	else
	{
		cout << ans.second;
	}

}