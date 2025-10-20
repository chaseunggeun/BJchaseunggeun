#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N, M;

unordered_set<string> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < M; i++)
	{
		string a;
		cin >> a;
		string t;
		for (char c : a)
		{
			if (c == ',')
			{
				s.erase(t);
				t = "";
				continue;
			}
			t += c;
		}
		s.erase(t);
		cout << s.size() << '\n';
	}

}
