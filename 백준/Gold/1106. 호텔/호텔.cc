#include <iostream>

using namespace std;

int c, n;
int dp[100001]; // i원 사용시 dp[i]명
pair<int, int> costCus[21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> costCus[i].first >> costCus[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        int cost = costCus[i].first;
        int cus = costCus[i].second;
        for (int j = 1; j <= 100000; j++)
        {
            if (j - cost >= 0) {
                dp[j] = max(dp[j], dp[j - cost] + cus);
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (dp[i] >= c) {
            cout << i << "\n";
            break;
        }
    }
}