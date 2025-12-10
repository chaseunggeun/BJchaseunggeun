#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> v;
vector<int> sum;
vector<bool> isPrime;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    isPrime.resize(n + 1, true);
    sum.resize(n + 1);
    
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        if (isPrime[i])
        {
            v.push_back(i);
            sum[i] += i;
        }
    }

    int ans = 0;
    int sum = 0;
    int st = 0, ed = 0;

    while (true) {
        if (sum >= n) {
            sum -= v[st];
            st++;
        }
        else if (ed == v.size()) {
            break;
        }
        else {
            sum += v[ed];
            ed++;
        }

        if (sum == n) {
            ans++;
        }
    }

    cout << ans;
}