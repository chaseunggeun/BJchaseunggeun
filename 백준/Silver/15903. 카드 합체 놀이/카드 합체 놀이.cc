#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	long long int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += pq.top();
		pq.pop();
	}
	cout << cnt;
}
