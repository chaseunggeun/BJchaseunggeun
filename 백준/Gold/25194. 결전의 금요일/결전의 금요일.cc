#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

int N;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	s.insert(0);

	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		vector<int> v;
		v.clear();

		for (int j : s)
		{
			v.push_back((j + t) % 7);
		}

		for (int j : v)
		{
			s.insert(j);
		}
	}
	
	if (s.count(4))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}