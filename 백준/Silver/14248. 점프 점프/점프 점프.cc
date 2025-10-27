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

int N, S;
int ans;
vector<int> v;
vector<bool> visit;

int dfs(int i)
{
	int ans = 1;
	int n1 = i - v[i];
	int n2 = i + v[i];
	if (n1 > 0 && !visit[n1])
	{
		visit[n1] = true;
		ans += dfs(n1);
	}

	if (n2 <= N && !visit[n2])
	{
		visit[n2] = true;
		ans += dfs(n2);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	cin >> S;

	visit[S] = true;
	cout << dfs(S);
}