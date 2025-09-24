#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M;
queue<int> q;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		m.insert({ a,i });
		m.insert({ b,i });
	}

	for (auto t : m)
	{
		q.push(t.second);
	}

	int ans = 0;
	while (N--)
	{
		ans = q.front();
		q.pop();
		q.push(ans);
	}

	cout << ans;
}