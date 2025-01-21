#include <iostream>
#include <map>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    map<int, int> ma;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ma.insert(make_pair(a, i));
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        auto b = ma.find(a);
        if (b == ma.end())cout << 0;
        else cout << 1;
        cout << " ";
        
    }
}