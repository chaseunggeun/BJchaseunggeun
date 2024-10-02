#include <iostream>
#include <stack>

using namespace std;
// 18352
string a;
stack<char> s;

int check() {
	int cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '{') {
			s.push('{');
		}
		else {
			if (s.empty()) {
				cnt++;
				s.push('{');
			}
			else {
				s.pop();
			}
		}
	}
	cnt += s.size() / 2;
	while (!s.empty())s.pop();
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i = 1;

	while (1) {
		cin >> a;
		if (a[0] == '-')break;
		cout << i << ". " << check() << "\n";
		i++;
	}

}