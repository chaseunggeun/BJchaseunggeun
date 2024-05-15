#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return (a.size() < b.size());
	return a < b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		vec.push_back(a);
	}

	//sort(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), cmp);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]<<"\n";
	}
}