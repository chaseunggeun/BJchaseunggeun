#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		cout << vec[i] << '\n';
	}
}