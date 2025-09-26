#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;
int n, a;
long long b;
vector<long long> v;
vector<long long> sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> b >> a;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	
	sum.resize(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		sum[i + 1] = sum[i] + v[i];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int cnt = min(i, a);

		long long ndc = sum[i - cnt];

		long long dc = sum[i] - sum[i - cnt];

		long long cost = ndc + dc / 2;

		if (cost <= b)
		{
			ans = i;
		}
		else
		{
			break;
		}
	}

	cout << ans;
}