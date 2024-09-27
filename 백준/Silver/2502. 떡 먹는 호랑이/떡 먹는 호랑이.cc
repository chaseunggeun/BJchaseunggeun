#include <iostream>

using namespace std;

int D, K;
pair<int, int> dp[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> D >> K;
	dp[1] = { 1,0 };
	dp[2] = { 0,1 };
	for (int i = 3; i <= D; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}
	int a = dp[D].first;
	int b = dp[D].second;
	for (int i = 1; i <= K; i++) {
		if ((K - a * i) % b == 0) {
			int j = (K - a * i) / b;
			cout << i << "\n" << j << endl;
			break;
		}
	}

}

