#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(&arr[1], &arr[n+1]);
	for (int i =1; i <= n; i++) {
		cout << arr[i] << "\n";
	}

}