#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<vector<int>> v;
vector<vector<pair<int, int>>> dp;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	v.resize(N, vector<int>(3));
	dp.resize(N, vector<pair<int, int>>(3));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[0][0] = { v[0][0], v[0][0] };
	dp[0][1] = { v[0][1], v[0][1] };
	dp[0][2] = { v[0][2], v[0][2] };

	for (int i = 1; i < N; i++)
	{
		dp[i][0].first = v[i][0] + max(dp[i - 1][0].first, dp[i - 1][1].first);
		dp[i][0].second = v[i][0] + min(dp[i - 1][0].second, dp[i - 1][1].second);

		dp[i][1].first = v[i][1] + max({ dp[i - 1][0].first, dp[i - 1][1].first, dp[i - 1][2].first });
		dp[i][1].second = v[i][1] + min({ dp[i - 1][0].second, dp[i - 1][1].second, dp[i - 1][2].second });

		dp[i][2].first = v[i][2] + max(dp[i - 1][1].first, dp[i - 1][2].first);
		dp[i][2].second = v[i][2] + min(dp[i - 1][1].second, dp[i - 1][2].second);
	}

	cout << max({ dp[N - 1][0].first, dp[N - 1][1].first, dp[N - 1][2].first }) << " ";
	cout << min({ dp[N - 1][0].second, dp[N - 1][1].second, dp[N - 1][2].second });
}
