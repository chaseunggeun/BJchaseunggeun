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

using namespace std;

pair<int, int> player[1010]; // <white, black>
int dp[1010][30][30];

int gogo(int i, int black, int white)
{
	if (i == 0)
		return 0;

	if (black < 0 || white < 0)
		return INT_MIN;

	if (black == 0 && white == 0)
		return 0;

	if (dp[i][black][white] > 0)
		return dp[i][black][white];

	int ans = 0;

	ans = max(
		max((gogo(i - 1, black - 1, white) + player[i].second),
			(gogo(i - 1, black, white - 1) + player[i].first)),
		gogo(i - 1, black, white)
	);

	dp[i][black][white] = ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;
	int a, b;

	while (cin >> a >> b)
	{
		player[cnt].first = a;
		player[cnt].second = b;
		cnt++;
	}

	cout << gogo(cnt - 1, 15, 15);
}