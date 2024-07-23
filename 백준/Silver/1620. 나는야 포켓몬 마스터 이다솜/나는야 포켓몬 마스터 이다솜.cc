#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string temp;
	map<string, int> a;
	map<int, string> a2;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		a[temp] = i;
		a2[i] = temp;
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (atoi(temp.c_str()) == 0) {
			cout << a[temp] << "\n";
		}
		else {
			cout << a2[atoi(temp.c_str())] << "\n";
		}
	}
}