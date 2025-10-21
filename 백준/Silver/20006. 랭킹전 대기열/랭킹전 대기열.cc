#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int p, m;

class room
{
public:
	int level;
	map<string, int> players;
	bool state = true;

	bool insert(string n, int l)
	{
		if (state && abs(level-l)<=10)
		{
			players.insert({ n,l });
			if (players.size() >= m)
			{
				state = false;
			}
			return true;
		}
		return false;
	}
};

vector<room*> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		int l;
		string n;
		cin >> l >> n;
		bool flag = true;
		if (!v.empty())
		{
			for (auto& t : v)
			{
				if (t->insert(n, l))
				{
					flag = false;
					break;
				}
			}
		}

		if(flag)
		{
			room* r = new room();
			r->level = l;
			r->insert(n, l);
			v.push_back(r);
		}
	}

	for (auto& t : v)
	{
		if (t->state)
		{
			cout << "Waiting!\n";
		}
		else
		{
			cout << "Started!\n";
		}

		for (auto& c : t->players)
		{
			cout << c.second << " " << c.first << "\n";
		}
	}

}
