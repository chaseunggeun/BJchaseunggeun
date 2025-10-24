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

int n, k;

vector<int> v; // 입력보관용
vector<int> parents;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0) break;
		v.assign(n, 0);
		parents.assign(n, -1);

		int idx = -1;
		int Pidx = -1;

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (v[i] == k) idx = i;

			if (i == 0)
			{
				continue;
			}

			if (v[i - 1] + 1 != v[i])
			{
				Pidx++;
			}

			parents[i] = Pidx;
		}

		int ans = 0;

		if (idx == -1 || parents[idx] == -1 || parents[parents[idx]] == -1)
		{
			ans = 0;
		}
		else
		{
			int par = parents[idx];
			int grandpar = parents[par];

			for (int i = 0; i < n; i++)
			{
				if (parents[i] == -1 || parents[parents[i]] == -1) continue;

				int i_parent = parents[i];
				int i_grandparent = parents[parents[i]];

				if (i_grandparent == grandpar && i_parent != par)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;

	}

}