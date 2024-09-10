#include <iostream>
using namespace std;
int T[16];
int P[16];
int dp[16];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = N; i > 0; i--) {
		int deadline;
		deadline = i + T[i];//i일차의 일이 끝나는 날
		if (deadline > N+1) {//일 못함
			dp[i] = dp[i + 1];//i일차 일 안함
		}
		else {//일 가능
			dp[i] = max(dp[i + 1], dp[deadline] + P[i]);
			//i일차 일 안하는 것 vs i일차 일 하고 i일차 일 끝난 뒤부터 일한거 더한 것
		}
	}
	cout << dp[1];
}