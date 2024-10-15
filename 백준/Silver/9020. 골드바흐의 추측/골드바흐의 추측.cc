#include <iostream>
#include <cmath>
using namespace std;

int t,n,a,b;

bool isit(int x) {
	if (x < 2) return false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		a = n / 2;
		b = n / 2;
		while (1) {
			if (isit(a) && isit(b)) {
				cout << a << " " << b << endl;
				break;
			}
			a -= 1;
			b += 1;
		}
	}
}