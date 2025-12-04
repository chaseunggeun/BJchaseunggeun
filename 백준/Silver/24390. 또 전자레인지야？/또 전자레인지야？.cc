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

string s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	int mi = stoi(s.substr(0, 2));
	int se = stoi(s.substr(3, 2));

	int cnt = 1;
	if (se >= 30)se -= 30;

	cnt += mi / 10 + mi % 10 + se / 10;
	cout << cnt;


}