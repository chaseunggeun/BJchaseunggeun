#include <iostream>

using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		string ans;
		cin >> ans;
		for (int i = 1; i < N; i++)
		{
			string a;
			cin >> a;
			ans = (ans + a < a + ans) ? ans + a : a + ans;
		}
		cout << ans << '\n';
	}
}