#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void check(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= N; i++) {
		visited[i] = true;
		arr[cnt] = i;
		check(i, cnt + 1);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	check(1,0);
}
