#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int N;
int ans;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second > p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t, s;
		cin >> t >> s;
		v.push_back({ t,s });
	}
	
	sort(v.begin(), v.end(), cmp);

	ans = v[0].second - v[0].first;
	for (int i = 1; i < N; i++)
	{
		if (v[i].second < ans)
		{
			ans = v[i].second - v[i].first;
		}
		else
		{
			ans = ans - v[i].first;
		}
	}

	if (ans < 0)
	{
		cout << -1;
		return 0;
	}
	cout << ans;





}
