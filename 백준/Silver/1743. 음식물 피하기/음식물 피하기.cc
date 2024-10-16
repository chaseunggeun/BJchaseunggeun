#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
bool arr[101][101];
bool visit[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int check(int x, int y) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int> p;
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { p.first + dx[i], p.second + dy[i] };
			if (visit[next.first][next.second])continue;
			if (arr[next.first][next.second]) {
				q.push({ next.first, next.second });
				cnt++;
			}
			visit[next.first][next.second] = true;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j])continue;
			int a = check(i, j);
			if (a > max)max = a;
		}
	}
	cout << max;
}