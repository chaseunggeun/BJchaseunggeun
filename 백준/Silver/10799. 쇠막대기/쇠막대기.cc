#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   string a;
   cin >> a;
   int cnt = 0;
   for (int i = 0; i < a.size(); i++) {
	   if (a[i] == '(') {
		   s.push(a[i]);
	   }
	   else{
		   if (a[i - 1] == ')') {
			   s.pop();
			   cnt++;
		   }
		   else {//레이저
			   s.pop();
			   cnt += s.size();
		   }
	   }
   }
   cout << cnt;
}