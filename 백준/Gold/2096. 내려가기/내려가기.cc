#include <iostream>

using namespace std;

pair<int, int> dp[2][4];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cin >> dp[1][1].first >> dp[1][2].first >> dp[1][3].first;
	dp[1][1].second = dp[1][1].first;
	dp[1][2].second = dp[1][2].first;
	dp[1][3].second = dp[1][3].first;

	if (N == 1) {
		cout << max(max(dp[1][1].first, dp[1][2].first), dp[1][3].first) << ' ';
		cout << min(min(dp[1][1].second, dp[1][2].second), dp[1][3].second);
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		int cur = i % 2;
		int prev = 1 - cur;

		cin >> dp[cur][1].first >> dp[cur][2].first >> dp[cur][3].first;
		dp[cur][1].second = dp[cur][1].first;
		dp[cur][2].second = dp[cur][2].first;
		dp[cur][3].second = dp[cur][3].first;

		dp[cur][1].first += max(dp[prev][1].first, dp[prev][2].first);
		dp[cur][2].first += max(max(dp[prev][1].first, dp[prev][2].first), dp[prev][3].first);
		dp[cur][3].first += max(dp[prev][2].first, dp[prev][3].first);

		dp[cur][1].second += min(dp[prev][1].second, dp[prev][2].second);
		dp[cur][2].second += min(min(dp[prev][1].second, dp[prev][2].second), dp[prev][3].second);
		dp[cur][3].second += min(dp[prev][2].second, dp[prev][3].second);

		if (i == N) {
			cout << max(max(dp[cur][1].first, dp[cur][2].first), dp[cur][3].first) << ' ';
			cout << min(min(dp[cur][1].second, dp[cur][2].second), dp[cur][3].second);
			return 0;
		}
	}
}
