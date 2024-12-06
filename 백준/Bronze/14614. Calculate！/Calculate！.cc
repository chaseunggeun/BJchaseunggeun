#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b;
    string c;
    cin >> a >> b;
    cin >> c;
    if((c[c.size()-1]-'0') %2 ==0)
        cout << a << '\n';
    else
    {
        int ans = a ^ b;
        cout << ans << '\n';
    }
}