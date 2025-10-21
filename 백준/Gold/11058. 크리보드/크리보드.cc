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

vector<long long> dp;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp.resize(N + 1);
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++)
		{
			dp[i] = max(dp[i], dp[j] * (i - 1 - j));
		}
	}

	cout << dp[N];
}
