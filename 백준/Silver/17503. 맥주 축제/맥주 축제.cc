#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N, K;
long long M;
vector<pair<int, int>> v;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	
	v.resize(K);

	for (int i = 0; i < K; i++)
	{
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;

	long long cur = 0;
	int ans = -1;

	for (int i = 0; i < K; i++)
	{
		int sunho = v[i].second;
		int dosu = v[i].first;

		pq.push(sunho);
		cur += sunho;

		if (pq.size() > N)
		{
			cur -= pq.top();
			pq.pop();
		}

		if (pq.size() == N && cur >= M)
		{
			ans = dosu;
			break;
		}
	}

	cout << ans << "\n";
}
