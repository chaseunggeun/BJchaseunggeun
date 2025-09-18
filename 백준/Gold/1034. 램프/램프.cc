#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M, K;
map<string, int> m;
vector<string> v;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	cin >> K;

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == '0')cnt++;
		}

		if (cnt <= K && (cnt % 2) == (K % 2))
		{
			if (m.find(v[i]) == m.end())
			{
				m.insert({ v[i], 1 });
			}
			else
			{
				m[v[i]]++;
			}
		}
	}

	for (auto a : m)
	{
		ans = max(ans, a.second);
	}
	cout << ans;
}
