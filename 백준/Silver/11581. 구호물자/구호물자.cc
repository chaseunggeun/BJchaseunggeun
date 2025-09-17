#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> visited;
bool flag = false;

void dfs(int u) {
	visited[u] = 1;

	for (int v : v[u]) {
		if (visited[v] == 1) {
			flag = true;
			return;
		}
		if (visited[v] == 0) {
			dfs(v);
			if (flag) return;
		}
	}

	visited[u] = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1);
	visited.resize(N + 1, 0);

	for (int i = 1; i < N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	dfs(1);

	if (flag)
		cout << "CYCLE" << endl;
	else
		cout << "NO CYCLE" << endl;

}