#include <iostream>
#include <vector>

using namespace std;
char pan1[8][8] = { {'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'} ,{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'} ,{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'} };
char pan2[8][8] = { {'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'} ,{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'} ,{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'} ,{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'} };

int white_first(char vec[50][50], int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (vec[x + i][y + j] != pan1[i][j]) {
				result++;
			}
		}
	}
	return result;
}

int black_first(char vec[50][50], int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (vec[x + i][y + j] != pan2[i][j]) {
				result++;
			}
		}
	}
	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int height, weight;
	cin >> height >> weight;
	char vec[50][50];
	for (int i = 0; i < height; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < weight; j++) {
			vec[i][j] = a[j];
		}
	}//이차원 벡터에 값 입력 완료
	int t_white, t_black, min = 64;
	for (int i = 0; i <= height - 8; i++) {
		for (int j = 0; j <= weight - 8; j++) {
			t_white = white_first(vec, i, j);
			t_black = black_first(vec, i, j);
			if (t_white < t_black) {
				if (t_white < min) {
					min = t_white;
				}
			}
			else {
				if (t_black < min) {
					min = t_black;
				}
			}
		}
	}
	cout << min;

}