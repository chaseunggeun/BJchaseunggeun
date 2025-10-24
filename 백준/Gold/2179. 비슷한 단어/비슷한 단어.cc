#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int N;
string ss1, ss2;
int ss1idx = INT_MAX, ss2idx = INT_MAX;
int cnt = -1;

void gogo(const string& s1, int idx1, const string& s2, int idx2)
{
	int cnt2 = 0;
	int size = min(s1.size(), s2.size());
	for (int i = 0; i < size; i++)
	{
		if (s1[i] == s2[i])
		{
			cnt2++;
		}
		else
		{
			break;
		}
	}

	if (cnt2 > cnt)
	{
		cnt = cnt2;
		ss1 = s1;
		ss2 = s2;
		ss1idx = idx1;
		ss2idx = idx2;
	}
	else if (cnt2 == cnt)
	{
		pair<int, int> cur = { min(ss1idx, ss2idx), max(ss1idx, ss2idx) };
		pair<int, int> next = { min(idx1, idx2), max(idx1, idx2) };

		if (next < cur)
		{
			ss1 = s1;
			ss2 = s2;
			ss1idx = idx1;
			ss2idx = idx2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<pair<string, int>> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back({ s, i });
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			gogo(v[i].first, v[i].second, v[j].first, v[j].second);
		}
	}

	if (ss1idx < ss2idx)
	{
		cout << ss1 << '\n' << ss2;
	}
	else
	{
		cout << ss2 << '\n' << ss1;
	}
}