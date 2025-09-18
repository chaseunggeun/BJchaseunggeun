#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N, S, D, F, B, K;
set<int> police;
int ans = -1;
queue<pair<int, int>> q;
bool visited[100001];

void bfs()
{
	q.push({ S, 0 });
	visited[S] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == D)
		{
			ans =cnt;
			break;
		}
		int next = cur + F;

		if (next >= 1 && next <= N && !police.count(next) && !visited[next])
		{
			visited[next] = true;
			q.push({ next, cnt + 1 });
		}

		next = cur - B;
		if (next >= 1 && next <= N && !police.count(next) && !visited[next])
		{
			visited[next] = true;
			q.push({ next, cnt + 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> D >> F >> B >> K;
	if (K > 0)
	{
		for (int i = 0; i < K; i++)
		{
			int a;
			cin >> a;
			police.insert(a);
		}
	}

	bfs();

	if (ans == -1)
	{
		cout << "BUG FOUND";
	}
	else
	{
		cout << ans;
	}
}