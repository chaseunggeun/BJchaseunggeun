#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int N, K, Q, M;
vector<bool> is_zol;
vector<int> chul;
vector<bool> v;
vector<int> sum;

void check(int a)
{
	if (is_zol[a]) return;

	for (int j = a; j <= N + 2; j += a)
	{
		if (is_zol[j]) continue;
		v[j] = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q >> M;

	chul.resize(Q);
	v.resize(N + 3);
	sum.resize(N + 3);

	is_zol.resize(N + 3, false);

	for (int i = 0; i < K; i++)
	{
		int t;
		cin >> t;
		is_zol[t] = true;
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> chul[i];
		check(chul[i]);
	}

	for (int i = 3; i <= N + 2; i++)
	{
		sum[i] = sum[i - 1];
		if (!v[i]) sum[i]++;
	}

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

}