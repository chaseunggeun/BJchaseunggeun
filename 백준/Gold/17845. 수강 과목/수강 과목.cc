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

int N, K;

vector<pair<int, int>> v;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	v.resize(K + 1);
	dp.resize(K + 1, vector<int>(N + 1));

	for (int i = 1; i <= K; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (v[i].second > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].second] + v[i].first);
			}
		}
	}

	cout << dp[K][N];
}