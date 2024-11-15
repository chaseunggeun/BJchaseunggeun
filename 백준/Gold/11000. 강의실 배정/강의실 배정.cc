#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first)pq.pop();
     }

    cout << pq.size();
}
