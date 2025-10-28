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

int N;
vector<int> wminus, wplus, mminus, mplus;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            mminus.push_back(a);
        }
        else {
            mplus.push_back(a);
        }
    }

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            wminus.push_back(a);
        }
        else {
            wplus.push_back(a);
        }
    }

    sort(mminus.begin(), mminus.end());
    sort(wplus.begin(), wplus.end());
    sort(mplus.begin(), mplus.end());
    sort(wminus.begin(), wminus.end());

    int ans = 0;
    int idx = 0;
    for (int i = mminus.size() - 1; i >= 0; i--) {
        if (idx >= wplus.size()) {
            break;
        }
        if (abs(mminus[i]) > wplus[idx]) {
            idx++;
            ans++;
        }
    }
    idx = 0;
    for (int i = wminus.size() - 1; i >= 0; i--) {
        if (idx >= mplus.size()) {
            break;
        }
        if (abs(wminus[i]) > mplus[idx]) {
            ans++;
            idx++;
        }
    }
    cout << ans;
}