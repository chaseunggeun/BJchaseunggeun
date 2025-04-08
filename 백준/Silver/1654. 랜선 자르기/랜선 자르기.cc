#include <iostream>
#include <algorithm>

using namespace std;

long long K, N, ans;
int arr[10000];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> K >> N;
	int right = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		if (arr[i] > right)right = arr[i];
	}
	ans = right;

	long long mid, div, left = 1;
	while (left <= right) {
		mid = (left + right) / 2;
		div = 0;
		if (left == right) {
			for (int i = 0; i < K; i++) div += (arr[i] / mid);
			if (div >= N) ans = mid;
			else ans = mid - 1;
			break;
		}

		for (int i = 0; i < K; i++) div += (arr[i] / mid);
		if (div >= N) left = mid + 1;
		else right = mid;
	}

	cout << ans;
}
