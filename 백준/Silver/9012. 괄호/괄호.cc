#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	cin.ignore();
	for (int i = 0; i < n; i++) {
		stack<char> st;
		string a;
		getline(cin, a);
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '(') st.push(a[j]);
			else {
				if (st.empty()) {
					st.push(a[j]);
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (st.empty())cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	
}