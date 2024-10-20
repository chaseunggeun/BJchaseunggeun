#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];
}
