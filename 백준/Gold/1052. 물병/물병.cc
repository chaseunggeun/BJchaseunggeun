#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N >> K;

	if (N <= K) cout << 0;
	else
	{
		int ans = 0;

		while (1) {
			int cnt = 0;
			int t = N;
			while (t > 0) {
				if (t % 2 == 0) {
					t /= 2;
				}
				else {
					t /= 2;
					cnt++;
				}
			}

			if (K >= cnt) {
				break;
			}

			N++;
			ans++;
		}
		cout << ans;

	}
}