#include <iostream>
using namespace std;
int arr[50][50];//0청소x 1벽 2청소o
int N, M, r, c, d;
int cnt = 0;

int turn() {
	return (d + 3) % 4;
}

bool checkFront() {
	if (d == 0) {
		if (arr[r - 1][c] == 0)return true;
	}
	else if (d == 1) {
		if (arr[r][c+1] == 0)return true;
	}
	else if (d == 2) {
		if (arr[r+1][c] == 0)return true;
	}
	else {
		if (arr[r][c-1] == 0)return true;
	}
	return false;
}
bool checkBack() {
	if (d == 0) {
		if (arr[r + 1][c] == 1)return true;
	}
	else if (d == 1) {
		if (arr[r][c - 1] == 1)return true;
	}
	else if (d == 2) {
		if (arr[r - 1][c] == 1)return true;
	}
	else {
		if (arr[r][c + 1] == 1)return true;
	}
	return false;
}

void goFront() {
	if (d == 0) {
		r--;
	}
	else if (d == 1) {
		c++;
	}
	else if (d == 2) {
		r++;
	}
	else {
		c--;
	}
}

void goBack() {
	if (d == 0) {
		r++;
	}
	else if (d == 1) {
		c--;
	}
	else if (d == 2) {
		r--;
	}
	else {
		c++;
	}
}

void check() {
	while (true) {
		if (arr[r][c] == 0) { // 현재 칸이 청소되지 않은 경우
			arr[r][c] = 2; // 청소
			cnt++;
		}

		bool cleaned = false;
		for (int i = 0; i < 4; i++) {
			d = turn(); // 왼쪽으로 회전
			if (checkFront()) { // 앞쪽에 청소되지 않은 공간이 있는 경우
				goFront();
				cleaned = true;
				break;
			}
		}

		if (cleaned) continue; // 청소 가능한 칸으로 이동한 경우 루프 계속

		// 네 방향 모두 청소되어 있거나 벽인 경우
		if (checkBack()) break; // 뒤가 벽인 경우 작동 종료
		goBack(); // 뒤로 이동
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	check();
	cout << cnt;
}