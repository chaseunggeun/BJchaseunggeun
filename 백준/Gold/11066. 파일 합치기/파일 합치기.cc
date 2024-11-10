#include <iostream>
using namespace std;

int sum[501];
int arr[501];
int dp[501][501];

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int i = 1; i < n; i++) {
            for (int x = 1; x <= n - i; x++) {
                int y = x + i;
                dp[x][y] = 50000000;

                for (int mid = x; mid < y; mid++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }
}
