#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<int> v;
int C;
int N, L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	int ans = 0;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];

		if (i >= L)
		{
			C -= v[i - L];
		}
		C += v[i];

		if (C >= 129 && C <= 138)
		{
			ans++;
		}

	}

	cout << ans;
}
