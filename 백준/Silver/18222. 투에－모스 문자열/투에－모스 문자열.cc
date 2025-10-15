#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;


long long N;
int gogo(long long i)
{
    if (i == 0) return 0;
    else if (i == 1) return 1;
    else if (i % 2 == 0)
    {
        return gogo(i / 2);
    }
    else
    {
        return 1 - gogo(i / 2);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << gogo(N - 1);
}

