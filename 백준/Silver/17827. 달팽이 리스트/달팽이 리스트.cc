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

int N, M, V;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> V;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	while (M--)
	{
		int a, idx;
		cin >> a;
		if (a < N)
		{
			idx = a + 1;
		}
		else
		{
			a = a - V + 1;
			a = a % (N - V + 1);
			idx = a + V;
		}
		cout << v[idx] << '\n';
	}
}