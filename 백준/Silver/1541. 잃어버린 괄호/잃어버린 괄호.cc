#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a;
	string num = "";
	bool m = false;
	int ans = 0;

	for (int i = 0; i <= a.size(); i++)
	{
		if (a[i] == '+' || a[i] == '-' || i == a.size())
		{
			if (m)
			{
				ans -= stoi(num);
				num = "";
			}
			else
			{
				ans += stoi(num);
				num = "";
			}
		}
		else
		{
			num += a[i];
		}

		if (a[i] == '-')
		{
			m = true;
		}
	}

	cout << ans;
}
