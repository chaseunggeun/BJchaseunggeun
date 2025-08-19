#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, K, H;
int arr[1000001];
vector<int> sub;

int zichim()
{
	int cnt = 0;
	for (int i = 0; i < sub.size(); i++)
	{
		if (sub[i] > H)cnt++;
	}
	return cnt;
}
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

	for (int i = 1; i <= N; i++)
	{
		int a = abs(arr[i] - arr[i - 1]);
		if (i == 1) a = 0;
		int b = abs(arr[i + 1] - arr[i]);
		if (i == N)b = 0;
		sub.push_back(max(a, b));
	}

	sort(sub.begin(), sub.end());
	while (1)
	{
		if (zichim() <= K)
		{
			cout << H;
			return 0;
		}
		H++;
	}
	//12344


}
