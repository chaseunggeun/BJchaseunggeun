#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

deque<int> topnee[4];

void rotate(int idx, int dir) {
	if (dir == 1) {
		int temp = topnee[idx].back();
		topnee[idx].pop_back();
		topnee[idx].push_front(temp);
	}
	else {
		int temp = topnee[idx].front();
		topnee[idx].pop_front();
		topnee[idx].push_back(temp);
	}
}

int cal() {
	int sum = 0;
	if (topnee[0][0] == 1) sum += 1;
	if (topnee[1][0] == 1) sum += 2;
	if (topnee[2][0] == 1) sum += 4;
	if (topnee[3][0] == 1) sum += 8;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    for (int i = 0; i < 4; ++i) {
        string st;
        cin >> st;
        for (char c : st) {
            topnee[i].push_back(c - '0');
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int num, dir;
        cin >> num >> dir;
        int idx = num - 1;

        vector<int> dirs(4, 0);
        dirs[idx] = dir;

        for (int j = idx; j < 3; ++j) {
            if (topnee[j][2] != topnee[j + 1][6]) {
                dirs[j + 1] = -dirs[j];
            }
            else {
                break;
            }
        }

        for (int j = idx; j > 0; --j) {
            if (topnee[j][6] != topnee[j - 1][2]) {
                dirs[j - 1] = -dirs[j];
            }
            else {
                break;
            }
        }

        for (int j = 0; j < 4; ++j) {
            if (dirs[j] != 0) {
                rotate(j, dirs[j]);
            }
        }
    }

    cout << cal();
}