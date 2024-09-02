#include <iostream>
#include <map>
using namespace std;

int main()
{
	int num;
	cin >> num;

	while (num--)
	{
		map<string, int> _map;
		int n;
		cin >> n;

		int result = 1;

		for (int i = 0; i < n; i++)
		{
			string name;
			string cloths;
			cin >> name >> cloths;
			_map[cloths]++;
		}

		for (auto& c : _map)
			result *= (c.second + 1);
		
		cout << result - 1 << '\n';
	}
}