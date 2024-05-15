#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	vector<int> vec;
	cin >> n;
	while (n != 0) {
		vec.push_back(n % 10);
		n /= 10;
	}
	sort(vec.rbegin(), vec.rend());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
}