#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N, M, Q;
vector<long long> rd;
vector<long long> cd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> Q;

	rd.resize(N + 1, 0);
	cd.resize(M + 1, 0);

	while (Q--)
	{
		int type, index, val;
		cin >> type >> index >> val;

		if (type == 1)
		{
			rd[index] += val;
		}
		else
		{
			cd[index] += val;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << rd[i] + cd[j] << " ";
		}
		cout << "\n";
	}
}
