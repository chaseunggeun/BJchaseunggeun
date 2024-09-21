#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;
int LCS()
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    int result = dp[a.size()][b.size()];
    return result;
}

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);

   cin >> a >> b;
   cout << LCS();
}