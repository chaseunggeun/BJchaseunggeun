#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
int N, K;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	if (arr[0] != 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		if (i + 1 == arr[i])
		{
			continue;
		}

		if (i + 1 < arr[i])
		{
			cout << 0;
			return 0;
		}

		arr[i] += K;
		sort(arr, arr + N);
		--i;
	}
	cout << 1;
}
