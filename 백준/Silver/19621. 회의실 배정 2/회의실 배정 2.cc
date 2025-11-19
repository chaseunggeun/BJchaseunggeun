#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int N;

vector<int> v;
vector<int> dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	v.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b >> v[i];
	}
	
	dp[0] = v[0];
	dp[1] = max(v[0], v[1]);

	for (int i = 2; i < N; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
	}
	cout << dp[N - 1];
}