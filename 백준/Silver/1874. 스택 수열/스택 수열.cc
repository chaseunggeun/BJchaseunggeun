#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	stack<int> st;
	vector<char> vec;
	int n, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (cnt <= x) {
			st.push(cnt);
			vec.push_back('+');
			cnt++;
		}
		if (x == st.top()) {
			st.pop();
			vec.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}

}