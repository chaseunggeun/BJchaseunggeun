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

long long N;
vector<int> v;

bool gogo(long long t) {
    for (int d : v) {
        if (t % d != 0) return false;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

    string s = to_string(N);

    for (char c : s) {
        if (c != '0') v.push_back(c - '0');
    }

    for (int len = 0; ; ++len) {
        long long limit = pow(10, len);

        long long b = N * limit;

        for (long long i = 0; i < limit; ++i) {
            long long t = b + i;

            if (gogo(t)) {
                cout << t << endl;
                return 0;
            }
        }
    }
}
