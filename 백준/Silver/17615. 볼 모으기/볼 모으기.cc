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
#include <memory>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    cin >> s;

    int red = 0;
    int blue = 0;

    for (char c : s) {
        if (c == 'R') red++;
        else blue++;
    }

    int ans = INT_MAX;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') cnt++;
        else break;
    }
    ans = min(ans, red - cnt);

    cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == 'R') cnt++;
        else break;
    }
    ans = min(ans, red - cnt);

    cnt = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'B') cnt++;
        else break;
    }
    ans = min(ans, blue - cnt);

    cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == 'B') cnt++;
        else break;
    }
    ans = min(ans, blue - cnt);

    cout << ans;

}