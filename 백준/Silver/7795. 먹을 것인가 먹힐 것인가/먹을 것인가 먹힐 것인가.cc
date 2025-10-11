#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, T;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        vector<int> v1(N);
        vector<int> v2(M);
        
        for (int i = 0; i < N; i++)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> v2[i];
        }

        sort(v1.begin(), v1.end(), greater<>());
        sort(v2.begin(), v2.end(), greater<>());

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (v1[i] > v2[j])
                {
                    cnt += (M - j);
                    break;
                }
            }
        }

        cout << cnt << '\n';
    }
}

//8 7 3 1 1
//6 3 1