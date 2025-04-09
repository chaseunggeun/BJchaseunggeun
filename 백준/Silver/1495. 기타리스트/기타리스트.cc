#include <iostream>
#include <algorithm>
using namespace std;
int N, S, M;
int arr[51];
bool dp[51][1001]; // i번째 노래 j값 가능 or 불가능
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> S >> M; // 개수, 기본, 최대

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    dp[0][S] = true;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (dp[i - 1][j])
            {
                if (j + arr[i] <= M)
                    dp[i][j + arr[i]] = true;
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] = true;
            }
        }

    }

    for (int i = M; i >= 0; i--)
    {
        if (dp[N][i])
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}