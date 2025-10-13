#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int P, Q, n, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	int i = 1;
	while (T--)
	{
		cin >> P >> Q;
		vector<long long> dp(P + 1);
		dp[1] = 1 % Q;
		if (P > 1)dp[2] = 1 % Q;
		for (int i = 3; i <= P; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % Q;
		}


		cout << "Case #" << i << ": " << dp[P] << '\n';
		i++;
	}
}

