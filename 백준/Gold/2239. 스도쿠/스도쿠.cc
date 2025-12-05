#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> ans;

int WhatBlock(int r, int c)
{
	if (r <= 3)
	{
		if (c <= 3)
		{
			return 1;
		}
		else if (c <= 6)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else if (r <= 6)
	{
		if (c <= 3)
		{
			return 4;
		}
		else if (c <= 6)
		{
			return 5;
		}
		else
		{
			return 6;
		}
	}
	else
	{
		if (c <= 3)
		{
			return 7;
		}
		else if (c <= 6)
		{
			return 8;
		}
		else
		{
			return 9;
		}
	}
}
vector<int> StEd(int blockNum)
{
	switch (blockNum)
	{
	case 1:
		return { 1,3,1,3 };
		break;

	case 2:
		return { 1,3,4,6 };
		break;

	case 3:
		return { 1,3,7,9 };
		break;

	case 4:
		return { 4,6,1,3 };
		break;

	case 5:
		return { 4,6,4,6 };
		break;

	case 6:
		return { 4,6,7,9 };
		break;

	case 7:
		return { 7,9,1,3 };
		break;

	case 8:
		return { 7,9,4,6 };
		break;

	case 9:
		return { 7,9,7,9 };
		break;
	default:
		break;
	}
}
bool CanN(int r, int c, int N)
{
	for (int i = 1; i <= 9; i++)
	{
		if (v[r][i] == N) return false;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (v[i][c] == N)return false;
	}
	int block = WhatBlock(r, c);
	vector<int> vv = StEd(block);
	for (int i = vv[0]; i <= vv[1]; i++)
	{
		for (int j = vv[2]; j <= vv[3]; j++)
		{
			if (v[i][j] == N)return false;
		}
	}
	return true;
}

void dfs(int r, int c)
{
	int nr = r;
	int nc = c + 1;
	while (1)
	{
		if (nc > 9)
		{
			nc = 1;
			nr++;
		}

		if (nr > 9) break;

		if (v[nr][nc] == 0) break;
		nc++;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (CanN(r, c, i))
		{
			v[r][c] = i;

			if (nr > 9)
			{
				for (int y = 1; y <= 9; y++)
				{
					for (int x = 1; x <= 9; x++)
					{
						cout << v[y][x];
					}
					cout << '\n';
				}
				exit(0);
			}

			dfs(nr, nc);

			v[r][c] = 0;
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(10, vector<int>(10));

	for (int i = 1; i <= 9; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= 9; j++)
		{
			v[i][j] = s[j-1] - '0';
		}
	}
	
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (v[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}

}