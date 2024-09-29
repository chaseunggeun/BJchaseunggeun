#include <iostream>

using namespace std;
int dp[1001][1001];
int arr[1001][1001];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]),dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	cout << dp[N][M];
}
