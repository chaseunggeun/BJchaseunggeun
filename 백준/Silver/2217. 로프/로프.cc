#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

bool compare(int i, int j) {
	return j < i;
}

int check(int i) {
	return arr[i] * (i+1);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, compare);
	int max = 0;
	for (int i = 0; i < n; i++) {
		int t = check(i);
		if (max < t)max = t;
	}
	cout << max;
}
