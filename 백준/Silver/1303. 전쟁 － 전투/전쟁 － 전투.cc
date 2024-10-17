#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
char arr[101][101];
vector<int> white;
vector<int> blue;
bool visitW[101][101];
bool visitB[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y, bool t) {
	int cnt = 1;
	//white
	if (t) {
		visitW[x][y] = true;
		queue<pair<int, int>> q;
		q.push({ x,y });
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && arr[nx][ny] == 'W' && !visitW[nx][ny]) {
					q.push({ nx, ny });
					visitW[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
	else {//blue
		visitB[x][y] = true;
		queue<pair<int, int>> q;
		q.push({ x,y });
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && arr[nx][ny] == 'B' && !visitB[nx][ny]) {
					q.push({ nx, ny });
					visitB[nx][ny] = true;
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			arr[i][j + 1] = a[j];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visitB[i][j] && arr[i][j] == 'B') {
				blue.push_back(dfs(i, j, 0));
			}
			if (!visitW[i][j] && arr[i][j] == 'W') {
				white.push_back(dfs(i, j, 1));
			}
		}
	}
	int bTot = 0, wTot = 0;
	for (int i = 0; i < blue.size(); i++) {
		bTot += pow(blue[i], 2);
	}
	for (int i = 0; i < white.size(); i++) {
		wTot += pow(white[i], 2);
	}
	cout << wTot << ' ' << bTot;
}