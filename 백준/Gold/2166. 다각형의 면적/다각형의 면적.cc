#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> v;

long double calc(int i, int j)
{
	long double a = v[0].first, b = v[0].second;
	long double c = v[i].first, d = v[i].second;
	long double e = v[j].first, f = v[j].second;

	return (a * d + c * f + e * b - c * b - e * d - a * f) / 2.0f;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	long double sum = 0.f;
	
	for (int i = 1; i < N-1; i++)
	{
		sum += calc(i, i + 1);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(sum) << "\n";
}