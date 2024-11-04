#include <iostream>
#include <cmath>

using namespace std;

int arr[2000001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	arr[1000000] = 0;
	arr[1000001] = 1;
	if (n < 0) {
		for (int i = 999999; i >= 1000000 + n; i--) {
			arr[i] = (arr[i + 2] - arr[i + 1]) % 1000000000;
		}
		if (arr[1000000 + n] < 0)cout << -1 << '\n';
		else cout << 1 << '\n';
		cout << abs(arr[1000000 + n]);
	}
	else if (n > 0) {
		for (int i = 1000002; i <= n + 1000000; i++) {
			arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;
		}
		cout << 1 << '\n' << arr[1000000 + n];
	}
	else {
		cout << 0 << '\n' << arr[1000000];
	}
}
