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
		vec[i][0] = x;
		vec[i][1] = y;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i][0] << " " << vec[i][1];
		cout << "\n";
	}
}