#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<vector<string>> dp;
int N;

string add(string num1, string num2) {
	string sum = "";
	int c = 0;
	int i = num1.length() - 1;
	int j = num2.length() - 1;

	while (i >= 0 || j >= 0 || c) {
		int current_sum = c;

		if (i >= 0) {
			current_sum += num1[i] - '0';
			i--;
		}
		if (j >= 0) {
			current_sum += num2[j] - '0';
			j--;
		}

		c = current_sum / 10;
		sum += to_string(current_sum % 10);
	}

	reverse(sum.begin(), sum.end());

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1, vector<int>(N + 1));
	dp.resize(N + 1, vector<string>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[1][1] = "1";

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dp[i][j] == "") continue;
			long long t = v[i][j];
			if (t == 0) continue;


			if (i + t <= N)
			{
				dp[i + t][j] = add(dp[i + t][j], dp[i][j]);
			}
			if (j + t <= N)
			{
				dp[i][j + t] = add(dp[i][j + t], dp[i][j]);
			}
		}
	}

	if (dp[N][N] == "")
	{
		cout << "0";
	}
	else
	{
		cout << dp[N][N];
	}
}
