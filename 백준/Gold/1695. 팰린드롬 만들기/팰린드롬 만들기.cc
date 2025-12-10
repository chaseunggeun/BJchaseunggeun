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
vector<int> v;
vector<vector<int>> dp;

int dfs(int left, int right)
{
    if (left >= right)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    if (v[left] == v[right])
    {
        return dp[left][right] = dfs(left + 1, right - 1);
    }
    else
    {
        return dp[left][right] = 1 + min(dfs(left + 1, right), dfs(left, right - 1));
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N;
    v.resize(N);
    dp.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    cout << dfs(0, N - 1);
}