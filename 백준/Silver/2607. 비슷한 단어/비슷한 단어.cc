#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;


vector<string> v;
int N;

int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	string a = v[0];
	for (int i = 1; i < N; i++)
	{
		if (abs((int)(a.size() - v[i].size())) > 1)
		{
			continue;
		}

		vector<int> abc(26, 0);
		for (char c : a) abc[c - 'A']++;
		for (char c : v[i]) abc[c - 'A']--;

		int cnt = 0;
		for (int i : abc)  cnt += abs(i);

		if (cnt <= 2)
		{
			ans++;
		}
	}

	cout << ans;
}

