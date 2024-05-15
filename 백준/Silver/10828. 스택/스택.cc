#include <iostream>
#include <stack>
using namespace std;

void order(string a, stack<int>& st) {
	if (a == "push") {
		int c;
		cin >> c;
		st.push(c);
	}
	else if (a == "pop") {
		if (st.empty()) {
			cout << -1 <<"\n";
		}
		else {
			cout << st.top() << "\n";
			 st.pop();
		}
	}
	else if (a == "size") {
		cout << st.size() << "\n";
	}
	else if (a == "empty") {
		cout << st.empty() << "\n";
	}
	else if (a == "top") {
		if (st.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout <<st.top() << "\n";
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	stack<int> st;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		order(a, st);
	}
	
}