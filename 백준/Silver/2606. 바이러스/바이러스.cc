#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> vec;
vector<bool> visit;
void search(int a) {
	visit[a] = true;
	for (int i = 0; i < vec.size(); i++) {
		if (!visit[i] && vec[a][i]) {
			search(i);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	vec.resize(n+1, vector<bool>(n+1, false));
	visit.resize(n+1, false);

	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		vec[x][y] = true;
		vec[y][x] = true;
	}
	search(1);
	int cnt = 0;
	for (int i = 0; i < visit.size(); i++) {
		if (visit[i])cnt++;
	}
	cout << cnt-1;
}