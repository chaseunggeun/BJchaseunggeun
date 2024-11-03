#include <iostream>
using namespace std;

int n;
int cost[100001], dist[100001];

long long solve(int n) {
	int MINcost = 1000000000;
	long long dist_sum = 0;

	for (int i = 1; i < n; i++) {
		if (cost[i] < MINcost) MINcost = cost[i];
		dist_sum += (long long)MINcost * (long long)dist[i];
	}

	return dist_sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) cin >> dist[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];
	cout << solve(n);
}
