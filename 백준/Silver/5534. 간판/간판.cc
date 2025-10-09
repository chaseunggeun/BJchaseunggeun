#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N;
string goal;
vector<string> v;

bool gogo(int idx)
{
	bool flag = false;
	vector<int> vc;
	vector<pair<int, int>> pair;

	for (int i = 0; i < v[idx].size(); ++i) {
		if (v[idx][i] == goal[0]) {
			vc.push_back(i);
		}
		else if (v[idx][i] == goal[1]) {
			for (int t : vc) {
				if (t >= i) break;
				pair.push_back({ t, i });
			}
		}
	}

	for (auto p : pair)
	{
		int dist = p.second - p.first;
		int num = p.second;
		int goalNum = 1;
		while (1)
		{
			num += dist;
			goalNum++;
			if (num >= v[idx].size())
			{
				break;
			}

			if (v[idx][num] != goal[goalNum])
			{
				break;
			}
			else if (v[idx][num] == goal[goalNum] && goalNum == goal.size() - 1)
			{
				return true;
			}
		}
	}

	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> goal;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (gogo(i))
		{
			cnt++;
		}
	}

	cout << cnt;
}
