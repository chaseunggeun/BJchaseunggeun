#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;
vector<vector<int>> v;
int ans;

int gogo(int dir)
{
    queue<int> q;

    if (dir == 1) // Up
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (v[i][j] != 0) q.push(v[i][j]);
                v[i][j] = 0;
            }

            int idx = 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (v[idx][j] == 0)
                {
                    v[idx][j] = data;
                }
                else if (v[idx][j] == data)
                {
                    v[idx][j] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    v[idx][j] = data;
                }
            }
        }
    }
    else if (dir == 2) // Down
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = n; i >= 1; i--)
            {
                if (v[i][j] != 0) q.push(v[i][j]);
                v[i][j] = 0;
            }

            int idx = n;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (v[idx][j] == 0)
                {
                    v[idx][j] = data;
                }
                else if (v[idx][j] == data)
                {
                    v[idx][j] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    v[idx][j] = data;
                }
            }
        }
    }
    else if (dir == 3) // L
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (v[i][j] != 0) q.push(v[i][j]);
                v[i][j] = 0;
            }

            int idx = 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (v[i][idx] == 0)
                {
                    v[i][idx] = data;
                }
                else if (v[i][idx] == data)
                {
                    v[i][idx] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    v[i][idx] = data;
                }
            }
        }
    }
    else // R
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= 1; j--)
            {
                if (v[i][j] != 0) q.push(v[i][j]);
                v[i][j] = 0;
            }

            int idx = n;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();

                if (v[i][idx] == 0)
                {
                    v[i][idx] = data;
                }
                else if (v[i][idx] == data)
                {
                    v[i][idx] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    v[i][idx] = data;
                }
            }
        }
    }

    int M = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            M = max(M, v[i][j]);
        }
    }
    return M;
}

void dfs(int d, int M)
{
    ans = max(ans, M);

    if (d == 5)
    {
        return;
    }

    vector<vector<int>> vv = v;

    for (int i = 1; i <= 4; i++)
    {
        dfs(d + 1, gogo(i));
        v = vv;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    v.resize(n + 1, vector<int>(n + 1));

    int M = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
            M = max(M, v[i][j]);
        }
    }

    dfs(0, M);

    cout << ans;

}