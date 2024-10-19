#include <iostream>

using namespace std;

int N;
int cnt = 0;
int col[16];  // col[i]는 i번째 행에 퀸이 놓인 열의 위치

bool promising(int row, int c) {
	for (int i = 0; i < row; i++) {
		// 같은 열에 있거나, 대각선에 있을 경우
		if (col[i] == c || abs(col[i] - c) == abs(i - row)) {
			return false;
		}
	}
	return true;
}

void queen(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {  // i는 열
		if (promising(row, i)) {
			col[row] = i;  // row번째 행에 i번째 열에 퀸을 놓는다.
			queen(row + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	queen(0);
	cout << cnt;
}