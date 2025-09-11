#include <iostream>
#include <vector>
// #include <string>

using namespace std;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<string> v(N, "");
	bool inc = true, dec = true;
	cin >> v[0];
	for (int i = 1; i < N; i++)
	{
		cin >> v[i];
		if (v[i] >= v[i - 1])
		{
			dec = false;
		}
		if (v[i] <= v[i - 1])
		{
			inc = false;
		}
	}

	if (dec)
	{
		cout << "DECREASING";
	}
	else if (inc)
	{
		cout << "INCREASING";
	}
	else
	{
		cout << "NEITHER";
	}


}

