#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int arr[126][126];
int ans[126][126];
int n;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i = 1;
	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
				ans[i][j] = INT_MAX;
			}
		}

		queue < pair<int, int>> q;
		ans[1][1] = arr[1][1];
		q.push({ 1, 1 });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
					if (ans[nx][ny] > ans[x][y] + arr[nx][ny]) {
						ans[nx][ny] = ans[x][y] + arr[nx][ny];
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << "Problem " << i << ": " << ans[n][n] << '\n';
		i++;
	}
}
