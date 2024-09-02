#include <iostream>
#include <queue>

using namespace std;
int N, K, cnt = 0;
bool visit[100000] = { false, };

int check() {
	queue<pair<int, int>> q;
	q.push({N, 0});
	visit[N] = true;
	while (!q.empty()) {
		pair<int,int> a = q.front();
		q.pop();
		if (a.first == K)return a.second;
		if (a.first > 0 && !visit[a.first-1]) {
			q.push({a.first-1, a.second+1});
			visit[a.first - 1] = true;
		}
		if (a.first < 100000 && !visit[a.first + 1]) {
			q.push({ a.first + 1, a.second + 1 });
			visit[a.first + 1] = true;
		}
		if (a.first <= 50000 && !visit[a.first * 2]) {
			q.push({ a.first * 2, a.second + 1 });
			visit[a.first * 2] = true;
		}
	}
}

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   cin >> N >> K;
   cout << check();
}