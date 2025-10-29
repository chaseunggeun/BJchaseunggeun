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

long long arr[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;

	arr[0] = 1;

	for (int i = 2; i < 5001; i += 2)
	{
		for (int j = 2; j <= i; j += 2)
		{
			arr[i] += arr[j - 2] * arr[i - j];
			arr[i] %= 1000000007;
		}
	}

	while(T--)
	{
		cin >> N;
		cout << arr[N] << "\n";
	}
}