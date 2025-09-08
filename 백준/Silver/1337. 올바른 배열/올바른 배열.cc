#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int iStartfind(int i)
{
	int cnt = 0;

	for (int j = v[i] + 4; j > v[i]; j--)
	{
		if (find(v.begin(), v.end(), j) == v.end()) // 없으면
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans = 4;

	for (int i = 0; i < N; i++)
	{
		int t = iStartfind(i);
		if (t < ans)ans = t;
	}

	cout << ans;
}
