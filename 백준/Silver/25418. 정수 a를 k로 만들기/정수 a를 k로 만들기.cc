#include <iostream>

using namespace std;
int A, K;
int dp[1000001];

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   cin >> A >> K;
   dp[A] = 0;

   for (int i = A+1; i <= K; i++) {
	   dp[i] = dp[i - 1] + 1;
	   if (i % 2 == 0) {
		   if (dp[i] > dp[i / 2] + 1 && i/2 >=A)dp[i] = dp[i / 2] + 1;
	   }
   }
   cout << dp[K];
}