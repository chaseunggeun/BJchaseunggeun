#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	long long arr[91];
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[N];
}
