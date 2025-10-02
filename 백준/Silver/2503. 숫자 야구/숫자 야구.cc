#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int T;
bool arr[1000];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 123; i <= 987; i++)
	{
		int a, b, c;
		a = i / 100;
		b = (i % 100) / 10;
		c = i % 10;

		if (a != b && b != c && c != a && a * b * c != 0)
		{
			arr[i] = true;
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n, s, b;
		cin >> n >> s >> b;
		for (int j = 123; j <= 987; j++)
		{
			if (!arr[j]) continue;
			int a1[3];
			a1[0] = j / 100;
			a1[1] = (j % 100) / 10;
			a1[2] = j % 10;

			int a2[3];
			a2[0] = n / 100;
			a2[1] = (n % 100) / 10;
			a2[2] = n % 10;

			int cnts = 0;
			int cntb = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (k == l && a1[k] == a2[l])
					{
						cnts++;
					}
					if (k != l && a1[k] == a2[l])
					{
						cntb++;
					}
				}
			}

			if (cnts != s || cntb != b)
			{
				arr[j] = false;
			}
		}
	}
	int cnt = 0;
	for (int i = 123; i <= 987; i++) 
	{
		if (arr[i]) cnt++;
	}
	cout << cnt;
}
