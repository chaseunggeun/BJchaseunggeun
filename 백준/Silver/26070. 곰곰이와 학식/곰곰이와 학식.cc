#include <iostream>

using namespace std;


long long A, B, C;
long long X, Y, Z;
long long ans1, ans2, ans3;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C >> X >> Y >> Z;

	long long a = A, b = B, c = C;
	long long x = X, y = Y, z = Z;
	ans1 += min(a, x);
	x -= min(a, x); y += x / 3;
	ans1 += min(b, y);
	y -= min(b, y); z += y / 3;
	ans1 += min(c, z);

	a = A, b = B, c = C;
	x = X, y = Y, z = Z;
	ans2 += min(b, y);
	y -= min(b, y); z += y / 3;
	ans2 += min(c, z);
	z -= min(c, z); x += z / 3;
	ans2 += min(a, x);

	a = A, b = B, c = C;
	x = X, y = Y, z = Z;
	ans3 += min(c, z);
	z -= min(c, z); x += z / 3;
	ans3 += min(a, x);
	x -= min(a, x); y += x / 3;
	ans3 += min(b, y);

	cout << max(ans1, max(ans2, ans3));
}