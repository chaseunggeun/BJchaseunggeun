#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int V, E;
vector<pair<int, pair<int, int>>> vec;
int parent[10001];

int find(int x) 
{
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, {a,b} });
	}

	sort(vec.begin(), vec.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int weight = 0;
	for (int i = 0; i < E; i++) {
		int start = vec[i].second.first;
		int end = vec[i].second.second;
		int cost = vec[i].first;

		int x = find(start);
		int y = find(end);

		if (x == y) continue;

		if (x < y) parent[y] = x;
		else parent[x] = y;

		weight += cost;
	}

	cout << weight;
}