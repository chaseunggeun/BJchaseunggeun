#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 18352
int N, M, K, X;
int arr[300001]; // i번째 칸으로 가는 최단경로
vector<int> vec[300001]; //vec[i]에 i에서 갈 수 있는 곳들 저장됨

void check() {
	queue<pair<int, int>> q;
	q.push({ X,0 });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int a = p.first;
		int b = p.second;
		for (int i = 0; i < vec[a].size(); i++) {
			if (arr[vec[a][i]] > b + 1) {
				q.push({ vec[a][i], b + 1 });
				arr[vec[a][i]] = b + 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= N; i++) {
		arr[i] = 300001;
	}
	arr[X] = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	check();
	bool t = false;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == K) {
			cout << i << "\n";
			t = true;
		}
	}
	if (!t) {
		cout << -1;
	}
}