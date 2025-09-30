#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long n;
    long long num = 1;
    int cnt = 1;

    while (cin >> n) {
        num = 1;
        cnt = 1;
        while (1) {
            num = num % n;
            if (num == 0) {
                break;
            }
            num = (num * 10) + 1;
            cnt++;
        }
        cout << cnt << '\n';
    }
}