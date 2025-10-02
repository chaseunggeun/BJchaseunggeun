#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		int a;
		cin >> a;
		string s1, s2;
		cin >> s1 >> s2;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < a; i++)
		{
			if (s1[i] == s2[i])continue;
			else
			{
				if (s1[i] == 'B')cnt1++;
				else cnt2++;
			}
		}
		cout << ((cnt1 > cnt2) ? cnt1 : cnt2);
		cout << "\n";
	}
}
