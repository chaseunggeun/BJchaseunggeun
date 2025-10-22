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

vector<int> v(8);
vector<int> p = { 0,1,2,3,4,5,6,7 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	do
	{
		bool flag = true;
		for (int i = 0; i < 8; i++)
		{
			int a1, a2, a3;
			a1 = v[p[(i - 1 + 8) % 8]];
			a2 = v[p[i]];
			a3 = v[p[(i + 1) % 8]];

			if ((a3 * 2 * a1) / (double)(a3 + a1) / sqrt(2) > a2)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans++;
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << ans;
}
