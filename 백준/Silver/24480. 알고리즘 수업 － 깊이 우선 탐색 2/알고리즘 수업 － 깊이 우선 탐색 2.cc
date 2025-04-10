#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R; // 정점수, 간선수, 시작정점
int order = 0;
bool isVisit[100001];
int visitNum[100001];

vector<int> v[100001];

void dfs(int curNode)
{
    if (isVisit[curNode]) return;
    isVisit[curNode] = true;
    visitNum[curNode] = ++order;

    for (int nextNode : v[curNode])
    {
        dfs(nextNode);
    }
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end(), greater<>());
	}

	dfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << visitNum[i] << '\n';
	}
	return 0;
}