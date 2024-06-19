#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int result = 0;
	while (t.size()>=s.size()) {
		if (s == t) {
			result = 1;
			break;
		}
		if (t[t.size() - 1] == 'A') {
			t.pop_back();
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	cout << result;
}