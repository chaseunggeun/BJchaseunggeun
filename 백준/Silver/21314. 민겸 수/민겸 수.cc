#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
string s = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> s;

	int idx = 0, cnt = 0;
	string ans = "";
	string temp = s;

	for (idx = 0; idx < temp.size(); ++idx) {
		if (temp[idx] == 'M') {
			cnt++;
		}
		else if (temp[idx] == 'K') {
			ans += '5';
			ans.insert(ans.size(), cnt, '0');
			cnt = 0;

		}
		if (idx + 1 == temp.size()) {
			ans.insert(ans.size(), cnt, '1');
		}
	}
	cout << ans << "\n";

	idx = 0;
	cnt = 0;
	ans = "";
	temp = s;
	for (idx = 0; idx < temp.size(); ++idx) {
		if (temp[idx] == 'M') {
			(idx == 0 || temp[idx - 1] == 'K') ? ans += '1' : ans += '0';
		}
		else if (temp[idx] == 'K') {
			ans += '5';
		}
	}

	cout << ans;
}