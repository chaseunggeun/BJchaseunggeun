#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

vector<int> dp;
vector<int> wok;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	dp.resize(N + 1, INT_MAX);

	vector<int> woks;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		woks.push_back(a);
	}

	set<int> s;
	for (int w : woks)
	{
		if (w <= N) s.insert(w);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			int sum = woks[i] + woks[j];
			if (sum <= N)
			{
				s.insert(sum);
			}
		}
	}

	wok.clear();
	for (int a : s) {
		wok.push_back(a);
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int t : wok)
		{
			if (i - t >= 0 && dp[i - t] != INT_MAX)
			{
				dp[i] = min(dp[i], dp[i - t] + 1);
			}
		}
	}

	if (dp[N] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp[N];
	}
	
}