#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int N, M;
int S, E;
vector<int> v;
vector<vector<bool>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	v.resize(N + 1);
	dp.resize(N + 1, vector<bool>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= N - 1; i++) {
		if (v[i] == v[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 2; j <= N; j++) {
			if (v[i] == v[j] && dp[i + 1][j - 1] == true) {
				dp[i][j] = true;
			}
		}
	}

	cin >> M;
	while (M--)
	{
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}
}