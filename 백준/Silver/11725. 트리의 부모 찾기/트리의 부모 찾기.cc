#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int parent[100001] = { 1 };

void findParents(int node) {

	for (int child = 0; child < tree[node].size(); child++) {
		int k = tree[node][child];
		if (!parent[k]) {
			parent[k] = node;
			findParents(k);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 1; i < N; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	findParents(1);

	for (int i = 2; i <= N; ++i) {
		cout << parent[i] << '\n';
	}
}
