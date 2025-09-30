#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<vector<int>> v;
vector<bool> visit;
int N;


int opp(int index) {
	if (index == 0) return 5;
	if (index == 1) return 3;
	if (index == 2) return 4;
	if (index == 3) return 1;
	if (index == 4) return 2;
	if (index == 5) return 0;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N, vector<int>(6));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> v[i][j];
		}
	}

    int ans = 0;

    for (int i = 0; i < 6; i++)
    {
        int cur = 0;

        int top = v[0][i];
        int bot = v[0][opp(i)];

        int side = 0;
        for (int k = 6; k >= 1; k--) {
            if (k != top && k != bot) {
                side = k;
                break;
            }
        }
        cur += side;

        for (int j = 1; j < N; j++)
        {
            bot = top;

            int boti = -1;
            for (int k = 0; k < 6; k++) {
                if (v[j][k] == bot) {
                    boti = k;
                    break;
                }
            }

            top = v[j][opp(boti)];

            side = 0;
            for (int k = 6; k >= 1; k--) {
                if (k != top && k != bot) {
                    side = k;
                    break;
                }
            }
            cur += side;
        }

        ans = max(ans, cur);
    }

    cout << ans << "\n";
}
