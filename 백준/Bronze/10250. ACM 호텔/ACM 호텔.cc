#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int H, W, N;
		cin >> H >> W >> N;
		int cnt = 1;
		while (N > H) {
			N -= H;
			cnt++;
		}
		if (cnt / 10 == 0) cout << N << 0 << cnt << "\n";
		else cout << N << cnt << "\n";
	}
}