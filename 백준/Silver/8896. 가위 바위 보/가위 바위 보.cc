#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	while (T--)
	{
		cin >> N;
		vector<pair<int, string>> v(N);
		for (int i = 0; i < N; i++)
		{
			v[i].first = i + 1;
			cin >> v[i].second;
		}

		int round = 0;
		while (v.size() > 1)
		{
			bool R = false, S = false, P = false;

			for (int i = 0; i < v.size(); i++)
			{
				char c = v[i].second[round];
				if (c == 'R') R = true;
				else if (c == 'S') S = true;
				else if (c == 'P') P = true;
			}

			int cnt = R + S + P;

			if (cnt == 1 || cnt == 3)
			{
				round++;
				continue;
			}

			char win;
			if (R && S) win = 'R';
			else if (S && P) win = 'S';
			else win = 'P';

			vector<pair<int, string>> next;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].second[round] == win)
				{
					next.push_back(v[i]);
				}
			}

			v = next;
			round++;
		}

		if (v.size() == 1)
		{
			cout << v[0].first << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}