#include <iostream>
#include <algorithm>
using namespace std;

int T , N;
pair<int, int> parr[100001];

void check() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> parr[i].first >> parr[i].second;
	}
	sort(&parr[1], &parr[N+1]);
	int cnt = 1;
	int tmp = 1; //first 1위 인덱스
	for (int i = 2; i <= N; i++) {
		if (parr[tmp].second > parr[i].second) {
			cnt++;
			tmp = i;
		}
	}
	cout << cnt << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		check();
	}
}