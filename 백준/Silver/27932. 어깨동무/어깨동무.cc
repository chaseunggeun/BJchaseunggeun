#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long N, K, H;
long long arr[1000001];
vector<long long> sub;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;


	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	if (N <= 1 || N == K)
	{
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++)
	{
		long long a = abs(arr[i] - arr[i - 1]);
		if (i == 1) a = 0;
		long long b = abs(arr[i + 1] - arr[i]);
		if (i == N)b = 0;
		sub.push_back(max(a, b));
	}

	sort(sub.begin(), sub.end());
	cout << sub[N - K - 1];
}