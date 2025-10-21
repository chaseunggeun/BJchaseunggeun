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

vector<vector<long long>> dp[3]; // 가로 세로 대각
vector<vector<int>> v;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1, vector<int>(N + 1));
	for (int i = 0; i < 3; i++)
	{
		dp[i].resize(N + 1, vector<long long>(N + 1));
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[0][1][2] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			if (i == 1 && j == 2) continue;
			if (v[i][j] == 1)continue;

			dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];

			if (i > 1) {
				dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];

				if (v[i - 1][j] == 0 && v[i][j - 1] == 0)
				{
					dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 3; i++)
	{
		ans += dp[i][N][N];
	}
	cout << ans;
}
