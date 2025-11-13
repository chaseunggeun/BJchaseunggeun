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

vector<int> v;
int dp[100001][5][5];

int cost(int from, int to)
{
	if (from == 0)
	{
		if (to == 0) return 0;
		return 2;
	}
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	while (cin >> t)
	{
		if (t == 0) break;
		v.push_back(t);
	}

	int n = v.size();

	for (int i = 0; i <= n; ++i)
	{
		for (int l = 0; l < 5; ++l)
		{
			for (int r = 0; r < 5; ++r)
			{
				dp[i][l][r] = INT_MAX;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int i = 0; i < n; ++i)
	{
		int target = v[i];

		for (int l = 0; l < 5; ++l)
		{
			for (int r = 0; r < 5; ++r)
			{
				int cur = dp[i][l][r];
				if (cur == INT_MAX) continue;

				if (target != r)
				{
					int moveCost = cost(l, target);
					dp[i + 1][target][r] = min(dp[i + 1][target][r], cur + moveCost);
				}

				if (target != l)
				{
					int move_cost = cost(r, target);
					dp[i + 1][l][target] = min(dp[i + 1][l][target], cur + move_cost);
				}
			}
		}
	}

	int ans = INT_MAX;
	for (int l = 0; l < 5; ++l)
	{
		for (int r = 0; r < 5; ++r)
		{
			ans = min(ans, dp[n][l][r]);
		}
	}

	cout << ans << "\n";

}