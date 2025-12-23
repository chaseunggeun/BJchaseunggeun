#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int G, P;
vector<int> parent;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[a] = b;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> G >> P;

    parent.resize(G + 1);
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (int i = 0; i < P; i++) {
        int gate;
        cin >> gate;

        int root = Find(gate);

        if (root == 0) break;

        Union(root, root - 1);
        cnt++;
    }

    cout << cnt;
    return 0;
}