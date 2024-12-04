#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

// 1987
using namespace std;
int n, m;
char arr[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxDepth = 0;
bool v[26];
void dfs(int x, int y, int depth) {
    v[arr[x][y] - 'A'] = true;
    maxDepth = max(maxDepth, depth);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
            if (!v[arr[nx][ny] - 'A']) {
                dfs(nx, ny, depth + 1);
            }
        }
    }
    v[arr[x][y] - 'A'] = false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = a[j - 1];
        }
    }
    dfs(1, 1, 1);
    cout << maxDepth;
}