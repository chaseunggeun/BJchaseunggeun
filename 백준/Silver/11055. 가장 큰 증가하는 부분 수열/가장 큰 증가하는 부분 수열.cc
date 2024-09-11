#include <iostream>

using namespace std;

int arr[1001];
int N;
int dp[1001];

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   cin >> N;
   for (int i = 1; i <= N; i++) {
	   cin >> arr[i];
	   dp[i] = arr[i];
   }
   //dp[a] = b => a번 인덱스 까지의 가장 큰 부분 수열의 합은 b 

   int max = 0;
   for (int i = 1; i <= N; i++) {
	   for (int j = 1; j < i; j++) {
		   if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) { // j추가
			   dp[i] = dp[j] + arr[i]; // j까지의 최대 부분수열 + arr[i]
		   }
	   }
	   if (max < dp[i])max = dp[i];
   }
   cout << max;
}