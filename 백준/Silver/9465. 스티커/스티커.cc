#include <iostream>
#include <algorithm>

// 9465
using namespace std;

int T, N;
int arr[3][100001];
int dp[3][100001];



int DP() {
	dp[1][1] = arr[1][1];
	dp[2][1] = arr[2][1];
	dp[1][2] = dp[2][1] + arr[1][2];
	dp[2][2] = dp[1][1] + arr[2][2];
	for (int i = 3; i <= N; i++) {//i열
		for (int j = 1; j <= 2; j++) { //j행
			if (j == 1) {
				dp[j][i] = dp[j+1][i - 2] + arr[j][i];
				if (dp[j][i] < dp[j + 1][i - 1] + arr[j][i]) {
					dp[j][i] = dp[j + 1][i - 1] + arr[j][i];
				}
			}
			else {
				dp[j][i] = dp[j-1][i - 2] + arr[j][i];
				if (dp[j][i] < dp[j - 1][i - 1] + arr[j][i]) {
					dp[j][i] = dp[j - 1][i - 1] + arr[j][i];
				}
			}
		}
	}
	return(max(dp[1][N], dp[2][N]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 1; j <= 2; j++) {
			for (int k = 1; k <= N; k++) {
				cin >> arr[j][k];
			}
		}
		cout << DP() <<'\n';
	}
}