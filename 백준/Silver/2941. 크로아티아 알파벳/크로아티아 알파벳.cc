#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        cnt++;
        if (a[i] == '=') {
            cnt--;
            if (a[i - 1] == 'z') {
                if (a[i - 2] == 'd') {
                    cnt--;
                }
            }
        }
        else if (a[i] == '-')cnt--;
        else if (a[i] == 'j') {
            if (a[i - 1] == 'l' || a[i - 1] == 'n')cnt--;
        }
    }
    cout << cnt;
}