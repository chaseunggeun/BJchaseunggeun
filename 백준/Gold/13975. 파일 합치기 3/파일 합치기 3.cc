#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            pq.push(a);
        }
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            pq.push(a + b);
            sum += a + b;
        }
        cout << sum << '\n';
    }
}
