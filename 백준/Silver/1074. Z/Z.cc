#include <iostream>
#include <cmath>

using namespace std;
int N, r, c;
int cnt=0;

void check(int x, int y, int size) {
	if (c == x && r == y) {
		cout << cnt;
		return;
	}
	else if (c < x + size && r < y + size && c >= x && r >= y) {
		check(x, y, size / 2);
		check(x + size / 2, y, size / 2);
		check(x, y + size / 2, size / 2);
		check(x + size / 2, y + size / 2, size / 2);
	}
	else {
		cnt += size * size;
	}
}
int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);

   cin >> N >> r >> c;
   check(0,0,pow(2,N));
}