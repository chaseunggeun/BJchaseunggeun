#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int n;
vector<int> v;
int sum, avg;
int t, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	avg = sum / n;
	for (int i = 0; i < n; i++)
	{
		if (v[i] < avg) b += avg - v[i];
		else if (v[i] > avg + 1) t += v[i] - (avg + 1);
	}

	if (t <= b)cout << b;
	else cout << t;
}
