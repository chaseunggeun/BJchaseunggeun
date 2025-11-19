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
vector<int> v;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    v.resize(N + 1);
    dp.resize(N + 1);
    for (int i = 1; i <= N; i++) 
    {
        cin >> v[i];
    }

    int m, M;
    for (int i = 0; i < N; i++) {
        m = v[i + 1];
        M = v[i + 1];
        for (int j = i + 1; j <= N; j++)
        {
            m = min(m, v[j]);
            M = max(M, v[j]);
            dp[j] = max(dp[j], dp[i] + M - m);
        }
    }

    cout << dp[N];
}

