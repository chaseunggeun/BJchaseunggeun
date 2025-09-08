#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
int dp[100001];
int Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a] << "\n";
	}
}
