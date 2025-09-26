#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

char arr[6][10];
int T;
int minCnt = INT_MAX;
int minD = INT_MAX;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int cnt)
{
	bool flag = false;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (arr[i][j] == 'o')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					int nxnx = i + dx[k] + dx[k];
					int nyny = j + dy[k] + dy[k];

					if (nxnx > 0 && nyny > 0 && nxnx <= 5 && nyny <= 9)
					{
						if (arr[nx][ny] == 'o' && arr[nxnx][nyny] == '.')
						{
							flag = true;
							arr[i][j] = '.';
							arr[nx][ny] = '.';
							arr[nxnx][nyny] = 'o';

							dfs(cnt + 1);

							arr[i][j] = 'o';
							arr[nx][ny] = 'o';
							arr[nxnx][nyny] = '.';
						}
					}

				}
			}
		}
	}

	if (flag == false)
	{
		int t = 0;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (arr[i][j] == 'o')
				{
					t++;
				}
			}
		}
		if (minCnt > t)
		{
			minCnt = t;
			minD = cnt;
		}
		else if (t == minCnt && cnt < minD)
		{
			minD = cnt;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		minCnt = INT_MAX;
		minD = INT_MAX;
		vector<pair<int, int>> v;
		for (int i = 1; i <= 5; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= s.size(); j++)
			{
				arr[i][j] = s[j - 1];
			}
		}

		dfs(0);

		cout << minCnt << " " << minD << "\n";
	}

}