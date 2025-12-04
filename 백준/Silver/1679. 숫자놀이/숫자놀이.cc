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

int N, K;

vector<int> v;
vector<int> dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);
	dp.resize(100001, INT_MAX);
	dp[0] = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cin >> K;

	int idx = 1;
	while (true)
	{
		dp[idx] = INT_MAX;

		for (int i = 0; i < v.size(); i++)
		{
			if (idx - v[i] < 0) continue;

			if (dp[idx - v[i]] == INT_MAX) continue;

			dp[idx] = min(dp[idx], dp[idx - v[i]] + 1);
		}

		if (dp[idx] > K) break;

		idx++;
	}

	string s;
	if (idx % 2)
	{
		s = "jjaksoon";
	}
	else
	{
		s = "holsoon";
	}

	cout << s << " win at " << idx;
}