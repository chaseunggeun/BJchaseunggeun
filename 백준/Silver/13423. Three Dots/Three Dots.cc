#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> v;

int gogo()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (abs(v[j] + v[i]) % 2 != 0)
			{
				continue;
			}

			int a = 0, b = N - 1;

			while (a <= b)
			{
				int mid = (a + b) / 2;
				if (v[mid] == (v[i] + v[j]) / 2)
				{
					cnt++;
					break;
				}
				else if (v[mid] < (v[i] + v[j]) / 2)
				{
					a = mid + 1;
				}
				else
				{
					b = mid - 1;
				}
			}
			
		}
	}
	return cnt;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		v.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << gogo() << "\n";
	}
}