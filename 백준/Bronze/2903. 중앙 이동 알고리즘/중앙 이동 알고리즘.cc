#include <iostream>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, a = 2;
    cin >> N;
    for (int i = 0; i < N; i++) {
        a = (a + (a - 1));
    }
    cout << a * a;
}