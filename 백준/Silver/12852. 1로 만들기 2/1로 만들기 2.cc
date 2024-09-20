#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[1000001];
int par[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	dp[N] = 0;
	par[N] = -1;
	for (int i = N-1; i >= 1; i--) {
		int a = 1000000;
		int b = 1000000;
		int c = 1000000;
		if (i * 3 <= N) {
			a = dp[i * 3] + 1;
		}
		if (i * 2 <= N) {
			b = dp[i * 2] + 1;
		}
		c = dp[i + 1] + 1;
		
		if (a < b) {
			if (a < c) {
				//a가 젤작음
				dp[i] = dp[i * 3] + 1;
				par[i] = i * 3;
			}
			else {
				//c가 젤작음
				dp[i] = dp[i + 1] + 1;
				par[i] = i + 1;
			}
		}
		else {
			if (b < c) {
				//b가 젤작음
				dp[i] = dp[i * 2] + 1;
				par[i] = i * 2;
			}
			else {
				//c가 젤작음
				dp[i] = dp[i + 1] + 1;
				par[i] = i + 1;
			}
		}
	}
	cout << dp[1] << "\n";
	int a = 1;
	vector<int> v;
	v.push_back(1);
	while (par[a]!=-1) {
		v.push_back(par[a]);
		a = par[a];
	}
	for (int i = v.size()-1; i >= 0; i-- ) {
		cout << v[i] << " ";
	}
}