#include <iostream>

using namespace std;
int arr[100001];
int sum[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int max = 0;
    // 왼쪽 벌 두 마리, 오른쪽 벌통
    for (int i = 2; i < N; i++) {
        int tempMax = (sum[N] - arr[1] - arr[i]) + (sum[N] - sum[i]);
        if (tempMax > max) {
            max = tempMax;
        }
    }

    // 오른쪽 벌 두 마리, 왼쪽 벌통
    for (int i = 2; i < N; i++) {
        int tempMax = (sum[N - 1] - arr[i]) + (sum[i - 1]);
        if (tempMax > max) {
            max = tempMax;
        }
    }

    // 양쪽 벌 한 마리씩, 가운데 벌통
    for (int i = 2; i < N; i++) {
        int tempMax = (sum[i] - arr[1]) + (sum[N] - sum[i - 1] - arr[N]);
        if (tempMax > max) {
            max = tempMax;
        }
    }
	cout << max;
}