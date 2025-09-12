#include <iostream>
#include <map>

using namespace std;
map<int, int> m;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		if (b == 1)
		{
			if (m.count(a))
			{
				cnt++;
			}
			else
			{
				m[a] = 1;
			}
		}
		else
		{
			if (m.count(a) == 0)
			{
				cnt++;
			}
			else
			{
				m.erase(a);
			}
		}
	}

	cout << cnt + m.size();
}