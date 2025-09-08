#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < N - 1; i++)
	{
		sum -= v[i];
		ans += v[i] * sum;
	}
	cout << ans;
}
