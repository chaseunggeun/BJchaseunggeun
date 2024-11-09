#include <iostream>
using namespace std;

int N;
int X, S;
int weaponPower, weaponPrice;

int main() {
    cin >> N;
    cin >> X >> S;
    bool result = false;

    for (int i = 0; i < N; i++) {
        cin >> weaponPrice >> weaponPower;
        if (weaponPrice <= X && weaponPower > S) {
            result = true;
            break;
        }
    }

    if (result) cout << "YES";
    else cout << "NO";

}