#include <iostream>
#include <queue>

using namespace std;

int map[1003][1003];
int result[1003][1003];
int n, m;

pair<int, int> goal;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push(goal);
	result[goal.first][goal.second] = 0;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { current.first + dy[i], current.second + dx[i] };

			if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
			if (result[next.first][next.second] != -1) continue;

			q.push(next);
			result[next.first][next.second] = result[current.first][current.second] + 1;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fill(&result[0][0], &result[1002][1002], -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2)goal = { i,j };
			if (map[i][j] == 0)result[i][j] = 0;
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}