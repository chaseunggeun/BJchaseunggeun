#include <iostream>
using namespace std;

int N, M;
int bus[101];
int arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> bus[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> arr[i][j];
    }

    int sum = 0;
    for (int i = 1; i < M; i++)
        sum += arr[bus[i - 1]][bus[i]];

    cout << sum << '\n';

    return 0;
}