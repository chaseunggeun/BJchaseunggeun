#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> A >> B;

	int ans = 987654321;
	for (int i = 0; i <= B.size() - A.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[j + i]) cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}