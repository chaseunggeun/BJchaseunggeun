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

string a, b;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;
	dp.resize(a.size() + 1, vector<int>(b.size() + 1));

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	int i = a.size();
	int j = b.size();
	string ans ="";
	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			j--;
		}
		else
		{
			ans+=a[i - 1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n' << ans;
}


//  @ A C A Y K P
//@ 0 0 0 0 0 0 0
//C 0 0 1 1 1 1 1
//A 0 1 1 
//P 0
//C 0
//A 0
//K 0