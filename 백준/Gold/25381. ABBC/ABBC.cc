#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;
string s;

int ans, A, AB, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;


	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A')
		{
			A++;
		}
		else if (s[i] == 'B')
		{
			if (A > 0)
			{
				A--;
				AB++;
			}
			else
			{
				B++;
			}
		}
		else if (s[i] == 'C')
		{
			if (B > 0)
			{
				B--;
				ans++;
			}
			else if (AB > 0)
			{
				AB--;
				ans++;
				A++;
			}
		}
	}

	cout << ans + AB;
}
