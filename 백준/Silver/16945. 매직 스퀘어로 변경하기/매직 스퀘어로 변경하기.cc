#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm>

using namespace std;
int arr[3][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[j][i];
		}
	}

	int ms[8][3][3] = {
		{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
		{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
		{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
		{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
		{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
		{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
		{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
		{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
	};

	int ans = 2100000000;

	for (int k = 0; k < 8; k++)
	{
		int cur = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				cur += abs(arr[j][i] - ms[k][j][i]);
			}
		}
		ans = min(ans, cur);
	}

	cout << ans << "\n";
}