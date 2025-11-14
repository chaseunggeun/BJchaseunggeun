#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;
int n, m;
int parent[1000001];

int find(int a)
{
    if (parent[a] == a) return (a);
    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    a = find(parent[a]);
    b = find(parent[b]);

    if (a != b)
    {
        if (a >= b) parent[a] = b;
        else parent[b] = a;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << i + 1;
            return 0;
        }
        Union(a, b);
    }
    cout << 0;
}