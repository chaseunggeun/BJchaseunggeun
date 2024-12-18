#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	int max = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = ::max(dp[i], dp[j] + 1);
			}
		}
		max = ::max(dp[i], max);
	}
	cout << max;
}