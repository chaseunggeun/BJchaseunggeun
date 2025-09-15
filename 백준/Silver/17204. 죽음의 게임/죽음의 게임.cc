#include <iostream>
#include <vector>

using namespace std;


vector<int> v;
int N, Bo, cnt;

void gogo()
{
	int cur = 0;
	vector<int> visit(N,0);

	while (1)
	{
		if (visit[cur] > 0)
		{
			cout << -1;
			return;
		}
		visit[cur]++;
		if (cur == Bo)
		{
			cout << cnt;
			return;
		}
		cur = v[cur];
		cnt++;

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Bo;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	gogo();
}