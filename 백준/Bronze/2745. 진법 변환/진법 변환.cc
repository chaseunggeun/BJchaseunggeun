#include <iostream>
using namespace std;

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    string a;
    int n;
    cin >> a >> n;

    for (int i = 0; i < a.length(); i++) {
        int digitValue = charToInt(a[i]);
        cnt = cnt * n + digitValue;
    }
    cout << cnt;

}