#include <iostream>
#include <vector>

using namespace std;

bool road[101][101][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            road[i][j][0] = true;
            road[i][j][1] = true;
        }
    }

    // 입력
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a * 100 + b > c * 100 + d) {
            int tmp;
            tmp = a; a = c; c = tmp;
            tmp = b; b = d; d = tmp;
        }
        if (a == c) {
            road[c][d][1] = false;
        }
        else {
            road[c][d][0] = false;
        }
    }

    // dp 초기화
    vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (road[i][0][0]) {
            dp[i][0] = 1;
        }
        else {
            break;
        }
    }
    for (int j = 1; j <= m; j++) {
        if (road[0][j][1]) {
            dp[0][j] = 1;
        }
        else {
            break;
        }
    }

    // Dp 풀이
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (road[i][j][0]) {
                dp[i][j] += dp[i - 1][j];
            }
            if (road[i][j][1]) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    // 출력
    cout << dp[n][m];
}
