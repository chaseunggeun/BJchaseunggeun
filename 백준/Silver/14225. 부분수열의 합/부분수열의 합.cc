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

int N;
bool check[2000001];
vector<int> v;

void gogo(int t, int sum)
{
    check[sum] = true;
    if (t == N)return;
    else
    {
        gogo(t + 1, sum);
        gogo(t + 1, sum + v[t]);
    }
}
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

    gogo(0, 0);

    int i = 0;
    while (check[i])
    {
        i++;
    }
    cout << i;
}