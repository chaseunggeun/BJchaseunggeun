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
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    v.resize(N);
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)flag = true;
    }
    int ans = 0;
    int st = 0, ed = 0;
    int cnt = v[0] % 2;

    while (st <= ed)
    {
        if (ed >= N) break;

        if (cnt <= K && ed+1<N)
        {
            ed++;
            if (v[ed] % 2)
            {
                cnt++;
            }
        }
        else
        {
            if (v[st] % 2)
            {
                cnt--;
            }
            st++;
        }

        ans = max(ans, ed - st + 1 - cnt);
    }
    if (flag)
    {
        ans =  max(ans, 1);
    }
    cout << ans;
}