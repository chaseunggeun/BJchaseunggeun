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

vector<vector<int>> v;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(m, 0));

    while (n--) {
        int idx = 0;

        for (int i = 0; i <= 2; i++) {
            int num;
            cin >> num;

            while (num--) {
                if (idx < m) {
                    v[m - 1 - idx][0] += i;
                }
                else {
                    v[0][idx - m + 1] += i;
                }
                idx++;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < m; j++) {
            v[i][j] = v[0][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}