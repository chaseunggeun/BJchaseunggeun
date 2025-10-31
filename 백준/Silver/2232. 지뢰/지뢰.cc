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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; ++i)
	{
		bool l = (i > 0 && v[i - 1] > v[i]);
		bool r = (i < N - 1 && v[i + 1] > v[i]);

		if (!l && !r)
		{
			cout << (i + 1) << "\n";
		}
	}
}