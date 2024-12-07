#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<int> v;

	for (int i = 1; i <= min(n, m); i++) {
		if (n%i == 0 && m%i == 0){
			v.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << n / v[i] << " " << m / v[i] << endl;
	}

	return 0;
}