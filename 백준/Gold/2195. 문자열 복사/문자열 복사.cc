#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

string s, p;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> p;


    for (int i = 0; i < p.length(); i++) {
        int maxx = 0;
        for (int j = 0; j < s.length(); j++) {
            int cnt = 0;
            while (p[i + cnt] == s[j + cnt]) cnt++;
            maxx = max(maxx, cnt);
        }

        i += (maxx - 1);
        ans++;
    }

    cout << ans;
}
