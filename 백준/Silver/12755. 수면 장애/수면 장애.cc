#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
string s = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    int len = 1;
    int cnt = 9;

    while (N > len * cnt) {
        N -= len * cnt;
        len++;
        cnt *= 10;
    }

    int num = pow(10, len - 1) + (N - 1) / len;

    cout << to_string(num)[(N - 1) % len];
}