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

vector<int> v;
int N;
int ans;

void dfs(int sum)
{
	if (v.size() == 2)
	{
		if (sum > ans)ans = sum;
		return;
	}

	for (int i = 1; i < v.size() - 1; i++)
	{
		sum += (v[i - 1] * v[i + 1]);
		int t = v[i];
		v.erase(v.begin() + i);

		dfs(sum);

		v.insert(v.begin() + i, t);
		sum -= (v[i - 1] * v[i + 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	dfs(0);

	cout << ans;
}
