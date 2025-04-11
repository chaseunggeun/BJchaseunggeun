#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[101];
bool isVisit[101];
vector<int> v;

void dfs(int cur, int start)
{
	if (isVisit[cur] == true)
	{
		if (cur == start) v.push_back(cur);
		return;
	}

	isVisit[cur] = true;
	dfs(arr[cur], start);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) isVisit[j] = false;
		dfs(i, i);
	}

	cout << v.size() << '\n';
	for (auto iter : v)
	{
		cout << iter << '\n';
	}
	return 0;
}