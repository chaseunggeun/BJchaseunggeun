#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500];
int N, M, B;
int check(int i) {
	int b = B;
	int time = 0;
	for (int k = 0; k < N; k++) {
		for (int j = 0; j < M; j++) {
			int t = arr[k][j];
			if (t > i) {//파야함
				while (t != i) {
					t--;
					b++;
					time += 2;
				}
			}
			else if (t < i) {//쌓아야함
				while (t != i) {
					t++;
					b--;
					time++;
				}
			}
		}
	}
	if (b < 0)return -1;
	return time;
	//i층으로 맞춤
	// 갖고있는 블럭 b개
	//시간 리턴
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> B;
	int max = 0;
	int min = 256;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max)max = arr[i][j];
			if (arr[i][j] < min)min = arr[i][j];
		}
	}
	int minresult = 100000000;
	int floor=max;
	for (int i = max; i >= min; i--) {
		int result = check(i);
		if (result == -1) continue;
		if (minresult > result) {
			floor = i;
			minresult = result;
		}
	}
	cout << minresult << " " << floor;
}
