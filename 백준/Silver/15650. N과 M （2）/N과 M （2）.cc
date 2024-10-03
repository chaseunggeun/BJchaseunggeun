#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[9];

void dfs(int num, int k) {
    if (k == M) { // M까지 들어갔을 시 실행
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else { // M까지 안 들어갔을 시
        for (int i = num; i <= N; i++) {
            arr[k] = i; // 값 저장
            dfs(i + 1, k + 1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N >> M;
    dfs(1, 0);
}
