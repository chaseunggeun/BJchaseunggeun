#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chi;
int visited[13], selected[13];
int N, M, res = 10000000;

void dfs(int depth, int cur)
{
    if (depth == M) {
        int dis, minDis, sum = 0;
        for (int i = 0; i < home.size(); i++) {
            minDis = 10000000;
            for (int j = 0; j < M; j++) {
                dis = abs(home[i].first - chi[selected[j]].first) + abs(home[i].second - chi[selected[j]].second);
                if (dis < minDis) {
                    minDis = dis;
                }
            }
            sum += minDis;
        }
        if (sum < res) {
            res = sum;
        }
    }
    else {
        for (int i = cur; i < chi.size(); i++) {
            if (!visited[i]) {
                visited[i] = 1;
                selected[depth] = i;
                dfs(depth + 1, i);
                visited[i] = 0;
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			if (a == 1)home.push_back({ i,j });
			else if (a == 2)chi.push_back({ i,j });
		}
	}
    dfs(0, 0);
    cout << res;
}
