#include <iostream>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   string a;
   cin >> a;
   int cnt = 0;
   for (int i = 1; i < a.size(); i++) {
	   if (a[i] != a[i -1])cnt++;
   }
   if (cnt % 2 == 1) {
	   cnt /= 2;
	   cnt++;
   }
   else {
	   cnt /= 2;
   }
   cout << cnt;
}