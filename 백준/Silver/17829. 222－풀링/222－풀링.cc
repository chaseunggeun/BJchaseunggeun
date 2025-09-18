#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1025][1025];
int N;

int gogo(int t, int i, int j)
{
	if (t == 1)return arr[i][j];

	vector<int> v;
	v.push_back(gogo(t / 2, i, j));
	v.push_back(gogo(t / 2, i + t / 2, j));
	v.push_back(gogo(t / 2, i, j + t / 2));
	v.push_back(gogo(t / 2, i + t / 2, j + t / 2));
	sort(v.begin(), v.end(), greater<>());
	return v[1];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << gogo(N, 1, 1);
}