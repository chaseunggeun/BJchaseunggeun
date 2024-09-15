#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int n;
int dp[100001][2];
int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   cin >> n;

   dp[1][0] = 1; // 오름
   dp[1][1] = 1; // 내림

   for (int i = 1; i <= n; i++) {
	   cin >> arr[i];
	   if (i == 1)continue;
	   if (arr[i - 1] == arr[i]) {
		   dp[i][0] = dp[i - 1][0] + 1;
		   dp[i][1] = dp[i - 1][1] + 1;
	   }
	   else if (arr[i - 1] < arr[i]) {
		   dp[i][0] = dp[i - 1][0] + 1;
		   dp[i][1] = 1;
	   }
	   else {
		   dp[i][1] = dp[i - 1][1] + 1;
		   dp[i][0] = 1;
	   }
   }
   sort(&dp[1][0], &dp[n][1]);
   if (dp[n][0] > dp[n][1])cout << dp[n][0];
   else cout << dp[n][1];
}