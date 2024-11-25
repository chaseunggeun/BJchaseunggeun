#include <iostream>
using namespace std;

int main() {
	int N, L, D,time=0,res=0;
	cin >> N >> L >> D;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) time++;
		for (int t = 1; t <= 5; t++) {
			if ((time % D) == 0) {
				res = time;
				i = N;
				break;
			}
			time++;
		}
		if (i == N && res == 0) {
			while (1) {
				if ((time % D) == 0) {
					res = time;
					break;
				}
				time++;
			}
		}
	}
	cout << res;

	return 0;
}