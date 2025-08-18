#include <iostream>
using namespace std;


int N, M;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
	}

	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
}