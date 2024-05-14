#include <iostream>
using namespace std;
int check(string a) {
    int c = 1;
    for (int i = 0; i < a.length()/2; i++) {
        if (a[i] != a[a.length() - i-1])c = 0;
    }
    return c;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    cout << check(a);

}