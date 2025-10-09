#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int N;
vector<int> v;
vector<int> cnt;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	v.resize(N);
	cnt.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; i++)
	{
		double ans = -100000000000;
		for (int j = i + 1; j < N; j++)
		{
			double cur = (double)(v[j] - v[i]) / (double)(j - i);
			if (cur > ans) {
				cnt[i]++;
				cnt[j]++;
				ans = cur;
			}
		}
	}

	sort(cnt.begin(), cnt.end());
	cout << cnt[N - 1];
}
