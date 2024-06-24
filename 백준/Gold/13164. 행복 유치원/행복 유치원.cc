#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K;
vector<int> vec;
vector<int> gap;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		if (i != 0) {
			gap.push_back(vec[i] - vec[i - 1]);
		}
	}

	sort(gap.begin(), gap.end());

	long long int sum = 0;
	for (int i = 0; i < N - K; i++) {
		sum += gap[i];
	}
	cout << sum;

}