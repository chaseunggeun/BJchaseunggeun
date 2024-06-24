#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	long int arr[41][2];
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int i = 2; i < 41; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		cout << arr[a][0]<< " " << arr[a][1]<< "\n";
	}
}