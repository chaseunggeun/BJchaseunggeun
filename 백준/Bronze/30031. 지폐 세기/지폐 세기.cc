#include <iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		switch (a)
		{
		case 136:
			sum += 1;
			break;
		case 142:
			sum += 5;
			break;
		case 148:
			sum += 10;
			break;
		case 154:
			sum += 50;
			break;
		default:
			break;
		}
	}

	cout << sum * 1000;
}