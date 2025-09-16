#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;
vector<int> dist;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++)
	{
		dist.push_back(v[i + 1] - v[i]);
	}
	sort(dist.begin(), dist.end(), greater<>());
	int ans = 0;

	for (int i = K-1; i < N-1; i++)
	{
		ans += dist[i];
	}
	cout << ans << endl;
}