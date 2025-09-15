#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[101][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 1111111111;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int cnt = 0;

                int s = arr[i][0];
                int d = arr[j][1];
                int i = arr[k][2];

                for (int l = 0; l < N; l++)
                {
                    if (arr[l][0] <= s && arr[l][1] <= d && arr[l][2] <= i)
                    {
                        cnt++;
                    }
                }

                if (cnt >= M)
                {
                    answer = min(answer, s + d + i);
                }
            }
        }
    }

    cout << answer;
}