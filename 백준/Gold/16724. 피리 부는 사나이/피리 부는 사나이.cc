#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> v;

vector<int> parent;
int N, M;

int find(int t)
{
    if (t == parent[t]) return t;

    return parent[t] = find(parent[t]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)return;
    parent[u] = v;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    v.resize(N, vector<char>(M));
    parent.resize(N * M);

    for (int i = 0; i < N * M; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; j++)
        {
            v[i][j] = a[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int cur = i * M + j;
            int ni = i;
            int nj = j;

            char dir = v[i][j];
            if (dir == 'U') ni--;
            else if (dir == 'D') ni++;
            else if (dir == 'L') nj--;
            else if (dir == 'R') nj++;

            int next = ni * M + nj;

            merge(cur, next);
        }
    }

    int ans = 0;
    for (int i = 0; i < N * M; i++)
    {
        if (parent[i] == i) {
            ans++;
        }
    }

    cout << ans;
}