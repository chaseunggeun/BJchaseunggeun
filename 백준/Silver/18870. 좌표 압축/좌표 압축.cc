#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> press(vector<int> vec) {
	vector<int> vec2 = vec;
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	
	vector<int> vec3;

	for (int i = 0; i < vec.size(); i++) {
		vec3.push_back(lower_bound(vec2.begin(), vec2.end(), vec[i]) - vec2.begin());
	}
	return vec3;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	vec = press(vec);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}