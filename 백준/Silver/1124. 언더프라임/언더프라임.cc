#include <iostream>
#include <cmath>
using namespace std;

int st, ed;
int arr[100001];
void input();
void solution();
int check(int i);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	solution();
	
}
void solution()
{
	for (int i = 2; i <= ed; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i * i <= ed; i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= ed; j += i)
		{
			arr[j] = 0;
		}
	}

	int sum = 0;
	for (int i = st; i <= ed; i++)
	{
		int count = check(i);

		if (count > 1 && count <= ed && arr[count] != 0)
		{
			sum++;
		}
	}
	cout << sum;
}

void input()
{
	cin >> st >> ed;
}

int check(int i)
{
	int cnt = 0;
	for (int j = 2; j * j <= i; j++)
	{
		if (arr[j] != 0)
		{
			while (i % j == 0)
			{
				i /= j;
				cnt++;
			}
		}
	}
	if (i > 1)
	{
		cnt++;
	}
	return cnt;

}