#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;
int N;
int dr[6] = { -2,-2,0,0,2,2 };
int dc[6] = { -1,1,-2,2,-1,1 };
vector<vector<bool>> v;
vector<vector<bool>> visit;
int r1, c1, r2, c2;

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r1,c1 }, 0 });
	visit[r1][c1] = true;

	while (!q.empty())
	{
		int r = q.front().first.first;
		int c = q.front().first.second;
		int t = q.front().second;
		if (r == r2 && c == c2)
		{
			cout << t;
			return;
		}
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;
			visit[nr][nc] = true;
			q.push({ { nr,nc },t + 1 });
		}
	}
	cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N, vector<bool>(N));
	visit.resize(N, vector<bool>(N));

	cin >> r1 >> c1 >> r2 >> c2;

	bfs();
}