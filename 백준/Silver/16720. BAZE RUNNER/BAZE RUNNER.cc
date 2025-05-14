#include <iostream>

using namespace std;

int n;
int arr[1000], res = 4000;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 2; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < 4; j++)
		{
			if (a[j] == '0')
			{
				arr[i] = j;
				break;
			}
		}
	}
	for (int j = 0; j < 4; j++)
	{
		int sum = 0;

		for (int i = 0; i < n - 2; i++)
		{
			int t = abs(arr[i] - j);
			if (t == 3)
				t = 1;

			sum += t;
		}
		res = min(sum, res);
	}
	cout << res + n + 2;
}