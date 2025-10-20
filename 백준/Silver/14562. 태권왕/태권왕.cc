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


int C;
int A, B;
void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({{ A, B }, 0});

	map<pair<int, int>, bool> visited;
	visited[{A, B}] = true;

	while (!q.empty())
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		
		q.pop();

		if (a == b)
		{
			cout << c << '\n';
			return;
		}

		int na1 = a + a;
		int nb1 = b + 3;

		int na2 = a + 1;
		int nb2 = b;

		if (na1 <= nb1 && visited.find({ na1, nb1 }) == visited.end())
		{
			visited[{na1, nb1}] = true;
			q.push({ {na1, nb1}, c + 1 });
		}

		if (na2 <= nb2 && visited.find({ na2, nb2 }) == visited.end())
		{
			visited[{na2, nb2}] = true;
			q.push({ {na2, nb2}, c + 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;

	while (C--)
	{
		cin >> A >> B;
		bfs();
	}
}
