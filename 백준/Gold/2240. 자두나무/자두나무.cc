#include <iostream>
#include <algorithm>
using namespace std;

int T, W;
int arr[1001][3];
int dp[1001][31][3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        int a;
        cin >> a;
        arr[i][a] = 1;
    }

    for (int i = 0; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j][1] = dp[i][j][2] = 0;
        }
    }

    dp[1][0][1] = arr[1][1];
    dp[1][1][2] = arr[1][2];

    int result = max(dp[1][0][1], dp[1][1][2]);

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if (j == 0) {
                dp[i][j][1] = dp[i - 1][j][1] + arr[i][1];
            }
            else {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + arr[i][1];
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + arr[i][2];
            }
            result = max(result, max(dp[i][j][1], dp[i][j][2]));
        }
    }

    cout << result;
}
