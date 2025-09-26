#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;

	string ans = "";
	int cnt = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'X')
		{
			cnt++;
		}
		if (s[i] == '.')
		{
			ans += '.';
			if (cnt % 2 == 0)
			{
				cnt = 0;
			}
			else
			{
				break;
			}
		}
		if (cnt == 2 && s[i + 1] != 'X')
		{
			ans += "BB";
			cnt = 0;
		}
		if (cnt == 4)
		{
			ans += "AAAA";
			cnt = 0;
		}
	}

	if (cnt % 2 == 1)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}