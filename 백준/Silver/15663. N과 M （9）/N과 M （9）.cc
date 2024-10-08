#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n, m;
int arr[9], id[9];
bool used[9];
map<vector<int>, bool> visited;

void solve(int num, vector<int> v) {
	if (num == m) {
		if (visited.find(v) != visited.end()) return;
		visited[v] = true;
		for (int i = 0; i < num; i++) cout << v[i] << ' ';
		cout << '\n';

		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			v.push_back(arr[i]);
			solve(num + 1, v);
			v.pop_back();
			used[i] = false;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		used[i] = false;
		cin >> arr[i];
	}
	sort(arr, arr + n);
	vector<int> v;
	solve(0, v);
}