#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> dp;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1);
	dp.resize(N + 1, vector<int>(6, 0));

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	dp[1][v[1].first] = 1;
	dp[1][v[1].second] = 1;
	
	int cnt = 1;
	int grade = min(v[1].first, v[1].second);

	for (int i = 2; i <= N; i++)
	{
		int a = v[i].first;
		int b = v[i].second;

		dp[i][a] = dp[i - 1][a] + 1;
		dp[i][b] = dp[i - 1][b] + 1;

		for (int j = 1; j <= 5; j++)
		{
			if (dp[i][j] > cnt)
			{
				cnt = dp[i][j];
				grade = j;
			}
			else if (dp[i][j] == cnt)
			{
				grade = min(grade, j);
			}
		}
	}

	cout << cnt << " " << grade;
}