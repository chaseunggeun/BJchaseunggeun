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

int T;
int n, m;
vector<int> v;
vector<vector<bool>> Map;
bool flag;

void dfs(int cur, int s)
{
	if (flag == false) return;

	for (int i = 1; i <= n; i++)
	{
		if (Map[cur][i] == true)
		{
			if (v[i] == s)
			{
				flag = false;
				return;
			}

			if (v[i] == 0)
			{
				v[i] = -s;
				dfs(i, -s);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	while (T--)
	{
		cin >> n >> m;
		v.assign(n + 1, 0);
		Map.assign(n + 1, vector<bool>(n + 1, false));

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			Map[a][b] = true;
			Map[b][a] = true;
		}
		flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (v[i] == 0)
			{
				v[i] = 1;
				dfs(i, 1);
			}

			if (flag == false) break;
		}

		if (flag) cout << "possible\n";
		else cout << "impossible\n";
	}
}


// v배열 = 선 표시
// dfs로 따라들어감
// 색칠배열 