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

int N, X;
vector<pair<int, int> > v;
int ans;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return (p1.first - p1.second) > (p2.first - p2.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> X;
	v.resize(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> v[i].first >> v[i].second;
		ans += v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	X -= N * 1000;

	for (int i = 0; i < N; i++) {
		if (X <= 0) {
			break;
		}
		if (v[i].first > v[i].second && X >= 4000) {
			ans += v[i].first - v[i].second;
			X -= 4000;
		}
	}

	cout << ans;
}