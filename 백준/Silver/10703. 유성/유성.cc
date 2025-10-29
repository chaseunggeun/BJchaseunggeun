#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int R, S;
vector<vector<char>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> R >> S;

    v.resize(R, vector<char>(S));
    for (int i = 0; i < R; i++) {
        string a;
        cin >> a;

        for (int j = 0; j < S; j++) {
            v[i][j] = a[j];
        }
    }

    int m = INT_MAX;

    for (int i = 0; i < S; i++) {
        int maxX = -1;
        int maxS = INT_MAX;
        for (int j = 0; j < R; j++) {
            if (v[j][i] == 'X') {
                maxX = j;
            }
            if (v[j][i] == '#' && maxS == INT_MAX) {
                maxS = j;
            }
        }

        if (maxX != -1 && maxS != INT_MAX) {
            m = min(maxS - maxX, m);
        }
    }

    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < S; j++) {
            if (v[i][j] == 'X') {
                v[i][j] = '.';
                v[i + m - 1][j] = 'X';
            }
        }
    }


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }

}