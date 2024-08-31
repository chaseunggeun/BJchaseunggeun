#include <iostream>
using namespace std;
bool arr[50][50];
int M, N, K, ans=0;
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0};

void reset() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			arr[i][j] = false;
		}
	}
	ans = 0;
}
void dfs(int x, int y) {
	arr[x][y] = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (arr[nx][ny])dfs(nx, ny);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = true;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		reset();
	}
}