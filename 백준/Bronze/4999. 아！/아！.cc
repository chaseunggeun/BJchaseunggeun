#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b; cin >> a >> b;
	if (a.size() < b.size()) {
		cout << "no";
	}
	else {
		cout << "go";
	}
}
