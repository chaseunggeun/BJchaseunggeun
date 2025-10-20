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

vector<vector<pair<int,long long>>> v;
vector<int> visit;
int N;
long long ans;

void dfs(int num, long long d)
{
	if (d > ans)ans = d;

	for (auto i : v[num])
	{
		if (!visit[i.first])
		{
			visit[i.first] = true;
			dfs(i.first, d + i.second);
			visit[i.first] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	visit[1] = true;
	dfs(1, 0);

	cout << ans;
}
