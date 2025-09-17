#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N, G;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--)
	{
		cin >> G;
		v.resize(G, 0);
		for (int i = 0; i < G; i++)
		{
			cin >> v[i];
		}
		int m = 1;
		while (1)
		{
			set<int> visit;
			bool flag = true;
			for (int i = 0; i < G; i++)
			{
				if (visit.count(v[i] % m))//이미 있으면
				{
					flag = false;
					break;
				}
				else
				{
					visit.insert(v[i] % m);
				}
			}
			if (flag)
			{
				cout << m <<"\n";
				break;
			}
			m++;
		}

	}
}