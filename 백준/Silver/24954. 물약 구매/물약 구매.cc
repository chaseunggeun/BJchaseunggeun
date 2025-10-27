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

int N;
vector<int> v;
vector<int> visit;
vector<vector<pair<int, int>>> dc;
int ans = INT_MAX;

void dfs(int item, int price)
{
	bool flag = true;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			flag = false;
		}
	}

	if (flag)
	{
		if (ans > price)
		{
			ans = price;
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) continue;

		// 할인시키기, 방문처리, 가격합에 적용
		int nprice = price + v[i];
		auto rollback = v;
		for (int j = 0; j < dc[i].size(); j++)
		{
			v[dc[i][j].first] -= dc[i][j].second;
			if (v[dc[i][j].first] < 1)v[dc[i][j].first] = 1;
		}
		visit[i] = true;
		dfs(i, nprice);
		visit[i] = false;
		v = rollback;
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
	dc.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			int a, b;
			cin >> a >> b;
			dc[i].push_back({ a,b });
		}
	}

	for (int i = 1; i <= N; i++)
	{
		auto rollback = v;
		for (int j = 0; j < dc[i].size(); j++)
		{
			v[dc[i][j].first] -= dc[i][j].second;
			if (v[dc[i][j].first] < 1)v[dc[i][j].first] = 1;
		}
		visit[i] = true;
		dfs(i, v[i]);
		visit[i] = false;
		v = rollback;
	}

	cout << ans;
}