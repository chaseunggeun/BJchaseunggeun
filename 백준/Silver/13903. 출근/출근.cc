#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> dx;
vector<int> dy;
vector<vector<int>> v;
int R, C, N;
int ans = INT_MAX;

int bfs() {
	queue<pair<pair<int, int>, int>> q;

	vector<vector<bool>> visited(R, vector<bool>(C, false));

	for (int i = 0; i < C; i++)
	{
		if (v[0][i] == 1)
		{
			q.push({ {0, i}, 0 });
			visited[0][i] = true;
		}
	}

	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		int curR = cur.first.first;
		int curC = cur.first.second;
		int curCnt = cur.second;

		if (curR == R - 1)
		{
			return curCnt;
		}

		for (int i = 0; i < N; i++)
		{
			int nRow = curR + dx[i];
			int nCol = curC + dy[i];

			if (nRow >= 0 && nCol >= 0 && nRow < R && nCol < C && v[nRow][nCol] == 1 && !visited[nRow][nCol])
			{
				visited[nRow][nCol] = true;
				q.push({ {nRow, nCol}, curCnt + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	v.resize(R, vector<int>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> v[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		dx.push_back(a);
		dy.push_back(b);
	}

	int ans = bfs();

	cout << ans;
}