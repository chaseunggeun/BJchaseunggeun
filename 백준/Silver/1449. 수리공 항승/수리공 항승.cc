#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int arr[1000];

int check() {
    int count = 1;
    int end = arr[0] + L - 1; // 첫 번째 테이프의 끝
    for (int i = 1; i < N; i++) {
        if (arr[i] <= end) {
            // 막혀있음
            continue;
        }
        else {
            // 안막힘
            count++;
            end = arr[i] + L - 1; // 테이프의 끝 업데이트
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << check() << endl;

    return 0;
}
