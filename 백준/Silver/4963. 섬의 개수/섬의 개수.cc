#include <iostream>
#include <queue>
using namespace std;
int arr[51][51];
bool visit[51][51];
int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,-1,1,0,1,-1 };
int x = -1, y = -1;
queue<pair<int, int>> q;
int cnt = 0;

void check() {
	visit[1][1] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = cur.second + dx[i];
			int nextY = cur.first + dy[i];
			if (nextX < 1 || nextY < 1 || nextX > x || nextY > y)continue;
			if (arr[nextY][nextX] && !visit[nextY][nextX]) {
				q.push({ nextY,nextX });
				visit[nextY][nextX] = true;
			}
		}

	}
}

void init() {
	cnt = 0;
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		cin >> x >> y;
		if (x == 0 && y == 0)break;
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				if (!visit[i][j] && arr[i][j] == 1) {
					q.push({ i,j });
					visit[i][j] = 1;
					check();
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		init();
	}

}