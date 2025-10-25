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
vector<pair<int, int>> v;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
		if (i != 0)
		{
			sum += (abs(v[i].first - v[i-1].first) + abs(v[i].second - v[i-1].second));
		}
	}
	sum += (abs(v[N - 1].first - v[0].first) + abs(v[N - 1].second - v[0].second));

	cout << sum;
}