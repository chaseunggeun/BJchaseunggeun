#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<bool> tree;

int find(int dest)
{
	vector<int> road;
	int cur = dest;
	while (cur > 0)
	{
		road.push_back(cur);
		cur /= 2;
	}

	for (int i = road.size()-1; i >= 0; i--)
	{
		if (tree[road[i]] == true) return road[i];
	}

	tree[dest] = true;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	vector<int> v(Q, 0);
	tree.resize(N+1, false);
	for (int i = 0; i < Q; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < Q; i++)
	{
		cout << find(v[i]) << "\n";
	}
}