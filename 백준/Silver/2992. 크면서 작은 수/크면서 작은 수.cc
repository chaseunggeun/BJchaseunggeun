#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<string> v;
string a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	
	if (next_permutation(a.begin(), a.end()))
		cout << a;
	else
		cout << 0;
}
