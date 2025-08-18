#include <iostream>
using namespace std;

int X, T, N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T >> X >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> K;
		bool b = false;
		for (int j = 0; j < K; j++)
		{
			int a;
			cin >> a;
			if (a == X)
			{
				b = true;
			}
		}

		if (!b)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}