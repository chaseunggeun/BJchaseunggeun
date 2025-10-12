#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N, K;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	dp.resize(N + 1, vector<int>(K + 1));

	for (int i = 0; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K];
}

