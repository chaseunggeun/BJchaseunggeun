#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> vec1(N);
	vector<int> vec2(N);
	for (int i = 0; i < N; i++) {
		cin >> vec1[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> vec2[i];
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	
	int s=0;

	for (int i = 0; i < N; i++) {
		s += vec1[i] * vec2[N - i-1];
	}
	cout << s;
	
}