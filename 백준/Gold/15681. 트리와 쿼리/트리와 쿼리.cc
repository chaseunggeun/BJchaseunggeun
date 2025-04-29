#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, R, Q; // 정점 수, 루트의 번호, 쿼리의 수

vector<int> arr[100001];
int dp[100001];
bool isVisit[100001];

void dfs(int _R)
{
	isVisit[_R] = true;
	dp[_R] = 1;

	// if (arr[_R].size() == 1) return;
	for (int i = 0; i < arr[_R].size(); i++)
	{
		if (!isVisit[arr[_R][i]])
		{
			dfs(arr[_R][i]);
			dp[_R] += dp[arr[_R][i]];
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;

	for (int i = 0; i < N-1; i++)
	{
		// 트리 정점
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(R);

	for (int i = 0; i < Q; i++)
	{
		int a;
		cin >> a;
		cout << dp[a] << '\n';
	}
	return 0;
}