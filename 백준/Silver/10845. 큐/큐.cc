#include <iostream>
#include <queue>
using namespace std;

void order(string a, queue<int>& qu) {
	if (a == "push") {
		int c;
		cin >> c;
		qu.push(c);
	}
	else if (a == "pop") {
		if (qu.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << qu.front() << "\n";
			qu.pop();
		}
	}
	else if (a == "size") {
		cout << qu.size() << "\n";
	}
	else if (a == "empty") {
		cout << qu.empty() << "\n";
	}
	else if (a == "front") {
		if (qu.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << qu.front() << "\n";
		}
	}
	else if (a == "back") {
		if (qu.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << qu.back() << "\n";
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	queue<int> qu;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		order(a, qu);
	}

}