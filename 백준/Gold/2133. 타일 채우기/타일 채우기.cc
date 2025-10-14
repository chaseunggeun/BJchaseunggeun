#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;


vector<int> v;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N + 1);
	v[0] = 1;
	v[2] = 3;

	for (int i = 4; i <= N; i+=2)
	{
		v[i] += v[i - 2] * v[2];
		for (int j = i-4; j >= 0; j-=2)
		{
			v[i] += (v[j] * 2);
		}
	}

	cout << v[N];
}

