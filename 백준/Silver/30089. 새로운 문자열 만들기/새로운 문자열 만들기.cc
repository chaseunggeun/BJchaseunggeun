#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;
int T;

bool check(string a, string b)
{
	string p = a + b;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != p[i])
		{
			return false;
		}
		if (a[i] != p[p.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;
		string _s = s;
		reverse(_s.begin(), _s.end());

		string ans = s + _s;

		for(int i = 0; i<s.size();i++)
		{
			string __s = _s.substr(1);
			if (check(s, __s))
			{
				_s = __s;
				ans = s + _s;
			}
			else
			{
				_s = __s;
			}
		}
		cout << ans << "\n";
	}


}