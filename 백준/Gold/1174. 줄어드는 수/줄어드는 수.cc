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
#include <memory>

using namespace std;

int N;
vector<long long> v;

void gogo(int t, long long n)
{
	v.push_back(n);
	for (int i = 0; i < 10; i++)
	{
		if (t <= i)break;
		gogo(i, n * 10 + i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 10; i++) gogo(i, i);

	sort(v.begin(), v.end());
	if (N > v.size())cout << -1;
	else cout << v[N - 1];
}