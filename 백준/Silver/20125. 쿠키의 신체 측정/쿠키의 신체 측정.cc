#include <iostream>

using namespace std;

int arr[1001][1001];
int visit[1001][1001];
int N;
// 하, 상, 좌, 우
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int length(int x, int y, int dir)
{
	int cnt = 0;
	int curX = x + dx[dir];
	int curY = y + dy[dir];
	while (1)
	{
		if (arr[curX][curY] == '*')
		{
			cnt++;
			curX += dx[dir];
			curY += dy[dir];
		}
		else
		{
			break;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	pair<int, int> head = { 0,0 };
	pair<int, int> heart = { 0,0 };
	pair<int, int> left = { 0,0 };
	pair<int, int> right = { 0,0 };
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = s[j - 1];
			if (arr[i][j] == '*' && head.first == 0)
			{
				head = { i,j };
				heart = { i + 1,j };
			}
			if (j >= 3 && arr[i][j] == '*' && arr[i][j - 2] == '*' && arr[i][j - 1] == '_' && left.first == 0)
			{
				right = { i - 1, j };
				left = { i - 1, j - 2 };
			}
		}
	}
	int leftArm = length(heart.first, heart.second, 2);
	int rightArm = length(heart.first, heart.second, 3);
	int back = length(heart.first, heart.second, 0);
	int leftLeg = length(left.first, left.second, 0);
	int rightLeg = length(right.first, right.second, 0);
	
	cout << heart.first << ' ' << heart.second << '\n';
	cout << leftArm << ' ' << rightArm << ' ' << back << ' ' << leftLeg << ' ' << rightLeg;
}
