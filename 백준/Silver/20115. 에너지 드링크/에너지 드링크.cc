#include <iostream>
#include <algorithm>

using namespace std;

int n;
float arr[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		arr[n - 1] += arr[i]/2;
	}
	cout << arr[n-1];
}
