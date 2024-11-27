#include <iostream>
#include <stack>
#include <algorithm>
//문자열 폭발
using namespace std;

stack<char> s;

string a, b;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		s.push(a[i]);
		if (a[i] == b[b.size() - 1] && s.size()>= b.size()) {
			string t = "";
			for (int j = 0; j < b.size(); j++) {
				t += s.top();
				s.pop();
			}
			reverse(t.begin(), t.end());
			if (t != b) {
				for (int k = 0; k < t.size(); k++) {
					s.push(t[k]);
				}
			}
		}
	}
	if (s.empty()) {
		cout << "FRULA";
		return 0;
	}
	string ans = "";
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}