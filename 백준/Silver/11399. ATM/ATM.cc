#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int cnt = 0;
	int a=0;
	for (int i = 0; i < N; i++) {
		a += arr[i];
		cnt += a;
	}
	cout << cnt;
}