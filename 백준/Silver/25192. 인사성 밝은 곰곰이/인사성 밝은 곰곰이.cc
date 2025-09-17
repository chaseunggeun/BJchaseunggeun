#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int cnt;
set<string> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		if (a == "ENTER")
		{
			s.clear();
		}
		else
		{
			if (!s.count(a))
			{
				cnt++;
				s.insert(a);
			}
		}

	}

	cout << cnt;
}