#include <iostream>
#include <string>

using namespace std;

string s, t;


bool gogo()
{
	int idx = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (s[idx] == t[i])
		{
			idx++;
		}
	}
	if (idx == s.size())
	{
		return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	while (cin >> s >> t)
	{
		if (gogo())
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}


}