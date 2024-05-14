#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b=1;
    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = a-1; j > i;j--) {
            cout << ' ';
        }
        for (int k = 0; k < (2 * i + 1); k++) {
            cout << '*';
        }
        cout << "\n";
    }
    for (int i = a - 1; i > 0; i--) {
        for (int k = 0; k < a - i; k++) {
            cout << " ";
        }
        for (int j = 0; j < (2 * i -1); j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
}