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

using namespace std;

int N, A, B;
priority_queue<pair<double, int>> pq;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> A >> B;
	
	long long D;
	cin >> D;

	long long P;
	P = A;
	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		pq.push({ (double)p / B, i });
		v.push_back(p);
	}

	while (!pq.empty())
	{
		if (pq.top().first > D / P)
		{
			D += v[pq.top().second];
			P += B;
			pq.pop();
		}
		else
		{
			break;
		}
	}

	cout << D / P;
}
