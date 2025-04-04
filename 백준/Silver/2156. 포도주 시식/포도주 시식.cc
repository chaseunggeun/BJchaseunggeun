#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10001];
    int dp[10001];
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = max({ dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1] });
    }


    cout << dp[N];
}
