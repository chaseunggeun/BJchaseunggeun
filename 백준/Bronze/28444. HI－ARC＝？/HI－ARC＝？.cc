#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[6];
	for (int i = 1; i <= 5; i++) {
		cin >> arr[i];
	}
	int a = arr[1] * arr[2] - arr[3] * arr[4] * arr[5];
	cout << a;
}