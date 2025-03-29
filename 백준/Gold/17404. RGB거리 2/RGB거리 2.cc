#include <iostream>

using namespace std;
int N;
int cost[1001][4];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    int n;
    int ans = 1000001;
    cin >> n;
    int r, g, b;
    for (int i = 1; i <= n; i++) {
        cin >> r >> g >> b;
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    for (int start = 0; start <= 2; start++) {
        int dp[1001][3];
        for (int j = 0; j <= 2; j++) {
            if (j == start) dp[1][start] = cost[1][start];
            else dp[1][j] = 1000001;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
        }
        for (int j = 0; j <= 2; j++) {
            if (j == start) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    cout << ans;



}