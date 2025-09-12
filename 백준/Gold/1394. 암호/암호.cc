#include <iostream>
#include <map>

using namespace std;

map<char, int> m;

long long power(long long base, long long exp) {
	long long res = 1;
	base %= 900528;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % 900528;
		base = (base * base) % 900528;
		exp /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, ans;
	cin >> a >> ans;
	for (int i = 0; i < a.size(); i++)
	{
		m[a[i]] = i + 1;
	}

	long long cnt = 0;

	for (int i = 0; i < ans.size(); i++)
	{
		cnt = (cnt+ power(a.size(), i)) % 900528;

		cnt = (cnt + (power(a.size(), ans.size() - i-1) * (m[ans[i]] - 1))) % 900528;
	}

	cout << cnt;
}