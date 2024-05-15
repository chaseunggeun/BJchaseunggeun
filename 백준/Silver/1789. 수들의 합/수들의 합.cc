#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long S;
	cin >> S;
	long long sum = 0, i = 1;
	while (sum < S) {
		sum += i;
		i++;
	}
	if (sum > S)i--;
	cout << i-1;
}