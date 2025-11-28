#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int N, M;
vector<vector<int>> v;
vector < vector < bool >> visit;

int dx[8] = { 0, 0, 1, 1, 1, -1,-1,-1 };
int dy[8] = { 1, -1, 0, 1, -1,0,1,-1 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] == true || v[nx][ny] == 0) continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N, vector<int>(M));
	visit.resize(N, vector<bool>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == 1 && visit[i][j]== false)
			{
				visit[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt;
}