#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	dp.resize(N + 1);
	dp[1] = 1;// 1 상근 , 0 창영
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}

	if (dp[N] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}
