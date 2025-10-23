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

using namespace std;

vector<int> v;
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n);

	int MM = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	long long l = 0;
	long long h = 1000000000000;
	long long ans = 0;
	while (l <= h)
	{
		long long mid = (l + h) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += mid / v[i];
		}

		if (sum >= m)
		{
			ans = mid;
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	cout << ans;
}
