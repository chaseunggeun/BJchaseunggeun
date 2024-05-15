#include <iostream>
using namespace std;

int main()
{
	int x, i=1;
	cin >> x;
	while (x > 0) {
		x -= i;
		i++;
	}//분자 분모 합이 i
	if(i%2==1) cout << i + x-1 << "/" << i -(i+x-1);
	else cout << i - (i + x - 1) << "/" << i + x - 1;
}