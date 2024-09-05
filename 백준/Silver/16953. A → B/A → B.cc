#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int a, b;
bool c = true;
vector<int> v;
void check() {
	queue<pair<long long, int>> q;
	q.push({ a,0 });
	while (!q.empty()) {
		pair<long long, int> p = q.front();
		q.pop();
		if (p.first == b) {
			v.push_back(p.second +1);
			continue;
		}
		if (p.first * 2 <= b) {
			q.push({ p.first * 2, p.second + 1 });
		}
		if (p.first * 10 + 1 <= b) {
			q.push({ p.first * 10 + 1, p.second + 1 });
		}
	}
	if (v.empty())c = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	check();
	sort(v.begin(), v.end());
	if (c) {
		cout << v[0];
	}
	else {
		cout << -1;
	}
}