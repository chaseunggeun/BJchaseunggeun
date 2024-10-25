#include <iostream>
using namespace std;

int main() {
    int t;
    int a, b;
    int cnt;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        cnt = a % 10;
        for(int j=1; j<b; j++){
            cnt *= a;
            cnt %= 10;
        }
        if (cnt == 0) cout << 10 << endl;
        else cout << cnt << endl;
    }
    return 0;
}