#include <iostream>
using namespace std;

int N, K;
int possible()
{
	int cnt = 0;
	for (int i = K - 1; i >= 1; i--)
	{
		cnt += i;
	}
	return cnt;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	int ball = N - K;

	if (ball < possible())
	{
		cout << -1;
		return 0;
	}
	ball -= possible();

	if (ball % K == 0)
	{
		cout << K - 1;
	}
	else
	{
		cout << K;
	}
}
