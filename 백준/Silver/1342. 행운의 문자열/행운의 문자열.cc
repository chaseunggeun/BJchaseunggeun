#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

string a;
int ans;
void checkup(string s)
{
	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] == s[i + 1])
		{
			return;
		}
	}
	ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;

	sort(a.begin(), a.end());

	do
	{
		checkup(a);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans;
}