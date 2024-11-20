#include <iostream>

using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
	if (n == 1)
	{
		cout << "*\n";
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < n / 2 + n % 2; ++j)
			{
				cout << "* ";
			}
			cout << "\n";
			for (int j = 0; j < n / 2; ++j)
			{
				cout << " *";
			}
			cout << "\n";
		}
	}
}
