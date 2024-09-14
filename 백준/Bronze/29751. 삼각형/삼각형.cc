#include <iostream>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   double a, b;
   cin >> a >> b;
   cout << fixed;
   cout.precision(1);
   cout << a * b / 2;
}