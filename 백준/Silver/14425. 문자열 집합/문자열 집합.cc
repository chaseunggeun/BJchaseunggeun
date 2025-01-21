#include <iostream>
#include <map>

using namespace std;

int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    map<string, bool> ma;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        ma.insert(make_pair(a, true));
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        if (ma[a] == true)
            cnt++;
        
    }
    cout << cnt;
}