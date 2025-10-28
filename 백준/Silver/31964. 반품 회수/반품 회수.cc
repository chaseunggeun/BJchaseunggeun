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

int N;
vector<int> pos;
vector<int> timing;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	pos.resize(N);
	timing.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> pos[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> timing[i];
	}

	int ans = pos[N - 1];

	for (int i = N - 1; i >= 0; i--)
	{
		if (ans < timing[i])
		{
			ans = timing[i];
		}
		if (i != 0)
		{
			ans += (pos[i] - pos[i - 1]);
		}
	}
	ans += pos[0];

	cout << ans;
}