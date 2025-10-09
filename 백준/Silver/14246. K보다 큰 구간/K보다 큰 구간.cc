#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N;
vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    long long k;
    cin >> k;

    long long cnt = 0;
    long long cur = 0;
    int start = 0;
    int end = 0;

    for (start = 0; start < N; start++) {
        while (end < N && cur <= k) {
            cur += v[end];
            end++;
        }

        if (cur > k) {
            cnt += (N - end + 1);
        }

        cur -= v[start];
    }

    cout << cnt;
}
