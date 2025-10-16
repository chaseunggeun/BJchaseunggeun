#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

long long N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	long long ans = 0;

	switch (N)
	{
	case 1:
		ans = M * 8;
		break;
	case 5:
		ans = M * 8 + 4;
		break;
	case 2:
		if (M % 2 == 0) ans = (M / 2) * 8 + 1;
		else ans = (M / 2) * 8 + 7;
		break;
	case 3:
		ans = M * 4 + 2;
		break;
	case 4:
		if (M % 2 == 0) ans = (M / 2) * 8 + 3;
		else ans = (M / 2) * 8 + 5;
		break;
	}

	cout << ans;
}
//01 02 03 04 05
//09 08 07 06
//   10 11 12 13
//17 16 15 14
//   18 19 20 21
//25 24 23 22
