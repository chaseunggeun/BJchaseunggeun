#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int mx;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> M >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int st = 1, ed = mx;
    int ans = 0;
    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        int cur = 0;
        for (int i = 0; i < N; i++)
        {
            cur += v[i] / mid;
        }

        if (cur >= M)
        {
            st = mid + 1;
            ans = mid;
        }
        else
        {
            ed = mid - 1;
        }
    }

    cout << ans;
}