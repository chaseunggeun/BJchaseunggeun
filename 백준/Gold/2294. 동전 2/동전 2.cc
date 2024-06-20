#include <iostream>
#include <algorithm>

using namespace std;
int N, K;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int dp[100001];
    cin >> N >> K;
    fill(dp, dp + 10001, 1000000000);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        dp[x] = 1;
        for (int j = 0; j < x; j++) {
            for (int k = j + x; k <= K; k += x) {
                dp[k] = min(dp[k], dp[k-x] + 1);
            }
        }

    }
    if (dp[K] > 10000)dp[K] = -1;
    cout << dp[K];
}