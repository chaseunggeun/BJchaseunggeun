#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

queue<pair<long long, long long>> q;
unordered_map<long long, bool> m;
long long L;
int N, K;

int dx[2] = { -1, 1 };

void bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		long long idx = q.front().first;
		long long d = q.front().second;

		q.pop();

		cout << d << "\n";
		cnt++;
		if (cnt == K)
		{
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			long long nidx = idx + dx[i];
			if (m.find(nidx) == m.end() && nidx >= 0 && nidx <= L)
			{
				q.push({ nidx, d + 1 });
				m.insert({ nidx,0 });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L >> N >> K;
	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		q.push({ a,0 });
		m.insert({ a,0 });
	}
	bfs();
}

