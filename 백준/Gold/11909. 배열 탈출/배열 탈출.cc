#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int ans = INT_MAX;
vector<vector<int>> v;
vector<vector<long long>> dp;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	v.resize(N + 1, vector<int>(N + 1));
	dp.resize(N + 1, vector<long long>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[1][1] = 0;

	for (int j = 2; j <= N; j++)
	{
		long long l = 0;
		if (v[1][j] >= v[1][j - 1])
		{
			l = v[1][j] - v[1][j - 1] + 1;
		}
		dp[1][j] = dp[1][j - 1] + l;
	}

	for (int i = 2; i <= N; i++)
	{
		long long l = 0;
		if (v[i][1] >= v[i - 1][1])
		{
			l = v[i][1] - v[i - 1][1] + 1;
		}
		dp[i][1] = dp[i - 1][1] + l;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			long long t = dp[i - 1][j];
			if (v[i][j] >= v[i - 1][j])
			{
				t += (long long)v[i][j] - v[i - 1][j] + 1;
			}

			long long l = dp[i][j - 1];
			if (v[i][j] >= v[i][j - 1])
			{
				l += (long long)v[i][j] - v[i][j - 1] + 1;
			}

			dp[i][j] = min(t, l);
		}
	}

	cout << dp[N][N];
}