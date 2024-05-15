#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x, y;
	cin >> n;
	vector<vector <int>> vec(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec[i][0] = y;
		vec[i][1] = x;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i][1] << " " << vec[i][0];
		cout << "\n";
	}
}