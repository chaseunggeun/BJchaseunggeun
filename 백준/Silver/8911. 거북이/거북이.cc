#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;

		int r = 0, c = 0, d = 0, rmax = 0, rmin = 0, cmax = 0, cmin = 0;

		for (char i : str)
		{
			switch (i)
			{
			case 'F':
				r += dir[d][0];
				c += dir[d][1];
				break;
			case 'B':
				r -= dir[d][0];
				c -= dir[d][1];
				break;
			case 'L':
				d = (d + 1) % 4;
				break;
			case 'R':
				d = ((d - 1) < 0 ? 3 : d - 1);
			}

			rmax = max(rmax, r);
			rmin = min(rmin, r);
			cmax = max(cmax, c);
			cmin = min(cmin, c);
		}

		cout << (rmax - rmin) * (cmax - cmin) << '\n';
	}
}
