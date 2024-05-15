#include <iostream>
using namespace std;

int arr[30];
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int a, N, M;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> N >> M;
		int result = 1;
		int x = 1;
		for (int j = M; j > M - N; j--) {
			result *= j;
			result /= x;
			x++;
		}
		cout << result << "\n";
	}
}