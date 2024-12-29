#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T;
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    
    int t = v[0].first;
    int m = 1;
    for (int i = 1; i < T; i++) {
        if (t <= v[i].second) {
            m++;
            t = v[i].first;
        }
    }
    cout << m;
}