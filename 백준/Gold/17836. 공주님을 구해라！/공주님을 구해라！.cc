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

using namespace std;

bool flag;
int ans = INT_MAX;
int N, M, T;

vector<vector<int>> v;
vector<vector<vector<bool>>> visit;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

struct info
{
	bool gram;
	int r;
	int c;
	int t;
	info(bool gram, int r, int c, int t) { this->gram = gram; this->r = r; this->c = c; this->t = t; }
};

void bfs()
{
	queue<info> q;
	q.push(info(false, 1, 1, 0));

	while (!q.empty())
	{
		bool gram = q.front().gram;
		int r = q.front().r;
		int c = q.front().c;
		int t = q.front().t;
		q.pop();
		if (r == N && c == M)
		{
			flag = true;
			ans = min(ans, t);
			continue;
		}
		if (t + 1 > T) continue;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr<1 || nr>N || nc<1 || nc>M) continue;
			if (gram)
			{
				if (!visit[nr][nc][1])
				{
					visit[nr][nc][1] = true;
					q.push(info(true, nr, nc, t + 1));
				}
			}
			else
			{
				if (v[nr][nc] == 1) continue;

				if (v[nr][nc] == 2)
				{
					if (!visit[nr][nc][1])
					{
						visit[nr][nc][1] = true;
						q.push(info(true, nr, nc, t + 1));
					}
				}
				else
				{
					if (!visit[nr][nc][0])
					{
						visit[nr][nc][0] = true;
						q.push(info(false, nr, nc, t + 1));
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	v.resize(N + 1, vector<int>(M + 1));
	visit.resize(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2, false)));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> v[i][j];
		}
	}

	bfs();

	if (flag)
	{
		cout << ans;
	}
	else
	{
		cout << "Fail";
	}
}