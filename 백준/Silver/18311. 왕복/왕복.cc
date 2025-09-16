#include <iostream>
#include <vector>

using namespace std;

long long N, K;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back({ a, i + 1 });
    }

    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt += v[i].first;
        if (cnt > K)
        {
            cout << v[i].second;
            return 0;
        }
    }

    for (int i = N - 1; i > -1; i--)
    {
        cnt += v[i].first;
        if (cnt > K)
        {
            cout << v[i].second;
            return 0;
        }
    }

}