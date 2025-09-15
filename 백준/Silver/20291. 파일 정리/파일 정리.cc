#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		a.erase(0, a.find('.') + 1);
		m[a]++;
	}

	for (auto a : m)
	{
		cout << a.first << " " << a.second << "\n";
	}
}