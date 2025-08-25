#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];

int M, N, K;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;
vector<int> v;
int cnt;

void BFS(int x, int y)
{
	q.push({ x, y });
	arr[y][x] = 1;
	cnt = 1;
	while (!q.empty())
	{
		int X, Y;
		X = q.front().first, Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx, ny;

			nx = X + dx[i];
			ny = Y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && (arr[ny][nx] == 0))
			{
				arr[ny][nx] = 1;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				arr[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[j][i] == 0)
			{
				cnt = 0;
				BFS(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}