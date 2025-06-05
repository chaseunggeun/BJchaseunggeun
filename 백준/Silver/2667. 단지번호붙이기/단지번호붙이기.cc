#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countDan;
int N;
char map[25][25];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y)
{
	map[y][x] = '0';
	int count = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[ny][nx] == '1')
		{
			count += dfs(nx, ny);
		}
	}
	return count;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (map[y][x] == '1')
			{
				countDan.push_back(dfs(x, y));
			}
		}
	}

	sort(countDan.begin(), countDan.end());
	
	int t = countDan.size();
	cout << t << '\n';
	for (int i = 0; i < t; i++)
	{
		cout << countDan[i] << '\n';
	}


}