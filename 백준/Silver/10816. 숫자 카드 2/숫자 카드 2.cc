#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		cout << upper_bound(arr, arr + N, a) - lower_bound(arr, arr + N, a) << "\n";
	}

}