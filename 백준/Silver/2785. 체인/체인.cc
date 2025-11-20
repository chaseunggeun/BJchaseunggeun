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
int cnt;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while (v.size() > 1)
    {
        v[v.size() - 2] += v[v.size() - 1];
        v[0]--;
        cnt++;
        v.pop_back();

        if (v[0] == 0)
        {
            for (int i = 0; i < v.size()-1; i++)
            {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }

    cout << cnt;
}

