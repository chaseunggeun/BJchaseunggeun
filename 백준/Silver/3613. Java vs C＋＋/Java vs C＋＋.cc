#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

string s1, s2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1;

	bool isSnake = false;
	bool isCamel = false;

	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			isCamel = true;
		}
		if (s1[i] == '_')
		{
			isSnake = true;
			if (i > 0 && s1[i - 1] == '_')
			{
				cout << "Error!";
				return 0;
			}
			if (i < s1.size() - 1 && !(s1[i + 1] >= 'a' && s1[i + 1] <= 'z'))
			{
				cout << "Error!";
				return 0;
			}
		}
	}

	if (isSnake && isCamel) {
		cout << "Error!";
		return 0;
	}
	if (s1[0] == '_' || s1[s1.size() - 1] == '_') {
		cout << "Error!";
		return 0;
	}
	if (s1[0] >= 'A' && s1[0] <= 'Z') {
		cout << "Error!";
		return 0;
	}


	if (isSnake)
	{
		bool flag = false;
		for (int i = 0; i < s1.size(); i++)
		{
			char c = s1[i];
			if (c == '_')
			{
				flag = true;
				continue;
			}

			if (flag)
			{
				c = c - ('a' - 'A');
				flag = false;
			}
			s2 += c;
		}
	}
	else
	{
		for (int i = 0; i < s1.size(); i++)
		{
			char c = s1[i];
			if (c >= 'A' && c <= 'Z')
			{
				s2 += '_';
				c = c + ('a' - 'A');
			}
			s2 += c;
		}
	}

	cout << s2;
}