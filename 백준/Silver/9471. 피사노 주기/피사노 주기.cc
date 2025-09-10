#include <iostream>

using namespace std;

int P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		int a;
		long long b;
		cin >> a >> b;

		int prev = 1, next = 1;
		long long j;
		for (j = 2; j < b * b; j++)
		{
			int t = prev;
			prev = next;
			next += t;

			prev %= b;
			next %= b;
			if (prev == 0 && next == 1)
			{
				break;
			}
		}
		cout << a << " " << j << "\n";
	}
}

