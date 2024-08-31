#include <iostream>
#include <queue>
using namespace std;
int N, M, V;
bool arr[1001][1001];
bool visited[1001];

void reset() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[v][i]) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int a = q.front();
		cout << a << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && arr[a][i] == true) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	reset();
	int v = V;
	dfs(v);
	reset();
	cout << "\n";
	v = V;
	bfs(v);

}