#include <iostream>

using namespace std;

int arr[10001];
int N, M, cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	long long sum = 0;

	while (end <= N)
	{
		if (sum >= M)
		{
			sum -= arr[start++];
		}
		else
		{
			if (end == N) break;
			sum += arr[end++];
		}

		if (sum == M)
		{
			cnt++;
		}
	}

	cout << cnt;
}