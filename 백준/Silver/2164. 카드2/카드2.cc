#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	bool a = false;
	while (1) {
		if (q.size() == 1)break;

		if (a == false) {
			q.pop();
			a = true;
		}
		else {
			q.push(q.front());
			q.pop();
			a = false;
		}
	}
	cout << q.front();
}