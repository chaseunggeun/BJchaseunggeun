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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	cin >> m >> n;

	vector<vector<int>> v(m, vector<int>(m, 0));

	vector<int> col(m + 1, 0);
	vector<int> row(m + 1, 0);

	while (n--) {
		int idx = 0;
		int num;
		int start, end;

		cin >> num;
		idx += num;

		cin >> num;
		if (num > 0) {
			start = idx;
			end = idx + num - 1;

			int cstart = max(0, start);
			int cend = min(m - 1, end);
			if (cstart <= cend) {
				int a = m - 1 - cend;
				int b = m - 1 - cstart;
				col[a] += 1;
				col[b + 1] -= 1;
			}

			int rstart = max(m, start);
			int rend = end;
			if (rstart <= rend) {
				int a = rstart - m + 1;
				int b = rend - m + 1;
				if (a < m) {
					b = min(b, m - 1);
					row[a] += 1;
					if (b + 1 < m) {
						row[b + 1] -= 1;
					}
				}
			}
			idx += num;
		}

		cin >> num;
		if (num > 0) {
			start = idx;
			end = idx + num - 1;

			int cstart = max(0, start);
			int cend = min(m - 1, end);
			if (cstart <= cend) {
				int a = m - 1 - cend;
				int b = m - 1 - cstart;
				col[a] += 2;
				col[b + 1] -= 2;
			}

			int rstart = max(m, start);
			int rend = end;
			if (rstart <= rend) {
				int a = rstart - m + 1;
				int b = rend - m + 1;
				if (a < m) {
					b = min(b, m - 1);
					row[a] += 2;
					if (b + 1 < m) {
						row[b + 1] -= 2;
					}
				}
			}
		}
	}

	int cur = 0;
	for (int i = 0; i < m; i++) {
		cur += col[i];
		v[i][0] = cur;
	}

	cur = 0;
	for (int j = 1; j < m; j++) {
		cur += row[j];
		v[0][j] = cur;
	}

	for (int j = 0; j < m; j++) {
		cout << v[0][j] + 1 << ' ';
	}
	cout << '\n';

	for (int i = 1; i < m; i++) {
		cout << v[i][0] + 1 << ' ';
		for (int j = 1; j < m; j++) {
			cout << v[0][j] + 1 << ' ';
		}
		cout << '\n';
	}
}