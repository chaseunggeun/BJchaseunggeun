#include <iostream>
#include <string>

using namespace std;

int a = 0, b = 0;
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	if (str.length() == 2) {
		cout << str[0] - '0' + str[1] - '0';
	}
	else if (str.length() == 3) {
		if (str[1] == '0') {
			cout << (str[0] - '0') * 10 + str[2] - '0' << endl;
		}
		else {
			cout << (str[1] - '0') * 10 + str[0] - '0' << endl;
		}
	}
	else {
		cout << (str[0] - '0') * 10 + (str[2] - '0') * 10 << endl;
	}
}