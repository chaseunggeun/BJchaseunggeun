#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> v;
vector<vector<bool>> visit;
int ans;

int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// 주변확인
// 자기보다 작으면 패스
// 자기보다 크면 dfs
// 자기랑 같으면 dfs

bool dfs(int n, int m)
{
	visit[n][m] = true;
	bool flag = true;

	for (int i = 0; i < 8; i++)
	{
		int nn = n + dx[i];
		int nm = m + dy[i];

		if (nn < 1 || nn > N || nm < 1 || nm > M)
		{
			continue;
		}

		if (v[nn][nm] > v[n][m])
		{
			flag = false;
		}
		else if (v[nn][nm] == v[n][m])
		{
			if (!visit[nn][nm])
			{
				if (!dfs(nn, nm))
				{
					flag = false;
				}
			}
		}
	}

	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N + 1, vector<int>(M + 1));
	visit.resize(N + 1, vector<bool>(M + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visit[i][j])
			{
				if (dfs(i, j))ans++;
				// visit[i][j] = true;
			}
		}
	}

	cout << ans;
}