#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> ans(N, 0);
	vector<int> cur(N, 0);
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> ans[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (ans[i] != cur[i])
		{
			cnt++;
			for (int j = i; j <= i + 2; j++)
			{
				if (j >= N) break;
				if (ans[j] == 1)ans[j] = 0;
				else ans[j] = 1;
			}
		}
	}

	cout << cnt;
}

