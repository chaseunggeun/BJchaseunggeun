#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	vector<int> dp(k+1);//dp[i]번째 칸은 i원을 만들 수 있는 경우의 수
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	dp[0] = 1;//0원을 만드는법 1개
	//동전마다 고려
	for (int i = 0; i < n; i++) {
		for (int j = vec[i]; j <= k; j++) {//i번째 동전으로 k칸까지의 경우의 수 채우기
			dp[j] = dp[j] + dp[j - vec[i]];//j칸 값은 원래 갖고있던 값 + 현재 동전으로 이 칸에 도달할 수 있는 경우의 수
		}
	}
	cout << dp[k];
}