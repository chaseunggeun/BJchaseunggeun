#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

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
	dp.resize(N + 200000, 0);
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	dp[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		dp[i] = dp[i + v[i] + 1] + 1;
	}
	for (int i = 0; i < N; i++)
	{
		cout << dp[i] << " ";
	}
}