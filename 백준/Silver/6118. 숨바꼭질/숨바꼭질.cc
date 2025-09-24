#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;

vector<vector<int>> v;
vector<int> visit;
vector<int> distv;

int num, cnt;
int dist;

void bfs()
{
	queue<int> q;
	q.push(1);
	visit[1] = true;
	distv[1] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			if (!visit[next])
			{
				visit[next] = true;
				distv[next] = distv[cur] + 1;
				q.push(next);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	v.resize(N+1);
	visit.resize(N + 1, false);
	distv.resize(N + 1, INT_MAX);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	for (int i = 1; i <= N; i++)
	{
		if (distv[i] != INT_MAX && distv[i] > dist)
		{
			dist = distv[i];
		}
	}

	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		if (distv[i] == dist)
		{
			cnt++;
			if (!flag)
			{
				num = i;
				flag = true;
			}
		}
	}

	cout << num << " " << dist << " " << cnt << '\n';

}