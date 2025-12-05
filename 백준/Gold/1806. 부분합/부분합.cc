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

int N, S;
vector<int> v;
vector<long long> sum;

int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	v.resize(N);
	sum.resize(N);


	int st = 0;
	int ed = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		sum[i] = v[i];
		if (i > 0)sum[i] += sum[i - 1];

		if (ed == 0 && sum[i] >= S)
		{
			ed = i;
		}

		if (v[i] >= S)
		{
			cout << 1;
			return 0;
		}
	}
	if (ed == 0)
	{
		cout << 0;
		return 0;
	}
	ans = ed - st + 1;

	while (st <= ed)
	{
		if (ed >= N)break;
		int dist = ed - st + 1;
		long long cur = sum[ed] - sum[st] + v[st];
		if (cur >= S)
		{
			ans = min(ans, dist);
			st++;
		}
		else
		{
			ed++;
		}
	}

	cout << ans;

}