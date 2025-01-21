#include <iostream>
#include <map>

using namespace std;

int n;
map<string, string, greater<>> ma;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        ma[a] = b;
    }
    for (auto itr = ma.begin(); itr != ma.end(); itr++)
    {
        if (itr->second == "enter") cout << itr->first << "\n";
    }
}