#include <iostream>
#include <queue>
using namespace std;

int n, cnt = 0;
bool arr[17][17];

void bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{1,2} });
    while (!q.empty()) {
        int mod = q.front().first;
        pair<int, int> p = q.front().second;
        q.pop();
        if (p.first == n && p.second == n) {
            cnt++;
            continue;
        }
        if ((mod == 0 || mod == 2) && p.second < n && !arr[p.first][p.second + 1]) {
            q.push({ 0,{p.first, p.second + 1} });
        }
        if ((mod == 1 || mod == 2) && p.first < n && !arr[p.first + 1][p.second]) {
            q.push({ 1,{p.first + 1, p.second} });
        }
        if (p.first < n && p.second < n && !arr[p.first + 1][p.second] && !arr[p.first][p.second + 1] && !arr[p.first + 1][p.second + 1]) {
            q.push({ 2, { p.first + 1, p.second + 1 } });
        }
    }
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];//1이 벽
		}
	}
	bfs();
	cout << cnt;
}