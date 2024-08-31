#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, string> m;
int M, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		string a, b;
		cin >> a >> b;
		m.insert({ a, b });
	}
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		cout << m[a] << "\n";
	}
}