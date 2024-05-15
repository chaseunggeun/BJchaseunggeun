#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, cnt = 0;
    cin >> N;
    for (int j = 0; j < N; j++) {
        string a;
        cin >> a;
        bool alpha[26] = {false};
        bool ch = true;
        alpha[a[0] - 'a'] = true;
        for (int i = 1; i < a.length(); i++) {
            if (a[i] != a[i - 1]) {
                if (alpha[a[i] - 'a']) {
                    ch = false;
                    break;
                }
            }
            alpha[a[i] - 'a'] = true;
        }
        if (ch)cnt++;
    }
    cout << cnt;
}