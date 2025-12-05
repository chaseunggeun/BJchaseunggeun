#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> m;

long long gogo(long long t)
{
	if (t == 0) return 1;

	if (m.count(t)) {
		return m[t];
	}

	m[t] = gogo(t / P) + gogo(t / Q);
	return m[t];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q;
	cout << gogo(N);
}