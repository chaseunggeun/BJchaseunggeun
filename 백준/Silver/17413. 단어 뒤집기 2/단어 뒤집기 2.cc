#include <iostream>
#include <string>
#include <stack>

using namespace std;
string a;
stack<char> s;
string res = "";
bool b;

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);

   getline(cin, a);
   for (int i = 0; i < a.size(); i++) {
	   if (a[i] == ' ') {
		   while (!s.empty()) {
			   res += s.top();
			   s.pop();
		   }
		   res += a[i];
	   }
	   else if (a[i] == '<') {
		   while (!s.empty()) {
			   res += s.top();
			   s.pop();
		   }
		   res += a[i];
		   b = true;
	   }
	   else if (a[i] == '>') {
		   res += a[i];
		   b = false;
	   }
	   else {
		   if (b == true) {
			   res += a[i];
		   }
		   else {
			   s.push(a[i]);
		   }
	   }
   }
   while (!s.empty()) {
	   res += s.top();
	   s.pop();
   }
   cout << res;
}