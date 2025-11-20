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

int N, K;
vector<int> v;
long long Ma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        if (v[i] > Ma)
        {
            Ma = v[i];
        }
    }

    long long low = 1;
    long long high = Ma;
    long long ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += v[i] / mid;
        }
        if (cnt >= K) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}

